#include <ZApplication.h>
#include <ZKbMainWidget.h>
#include <ZSingleSelectDlg.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <getopt.h>
#include <dirent.h>
#include <sys/stat.h>

int mfd = -1;
int pid = 0;
int paused = 0;
int menu_mode = 0;

/*static void get_exe_name(char * buffer)
{
  char                                  linkname[64];
  register pid_t                  pid;
  register unsigned long offset;

  pid = getpid();
  snprintf(&linkname[0], sizeof(linkname), "/proc/%i/exe", pid);
  if (readlink(&linkname[0], buffer, PATH_MAX) == -1)
    offset = 0;
  else
  {
      offset = strlen(buffer);
      while (offset && buffer[offset - 1] != '/') --offset;
      if (offset && buffer[offset - 1] == '/') --offset;

  }
  buffer[offset] = 0;
}
*/

class MyZDialog : public ZKbMainWidget
{
    Q_OBJECT

public:
    MyZDialog();
    ~MyZDialog();
    void keyPressEvent(QKeyEvent *event);
    void focusOutEvent(QFocusEvent* event);
};

MyZDialog::MyZDialog() : 
    ZKbMainWidget(ZHeader::FULL_TYPE, NULL, "ZMainWidget", 0)
{
	setFullScreenMode(true, true);
	::system("pmtool -n -t 7200 -b 7200");
}

MyZDialog::~MyZDialog()
{
	::system("pmtool -n -b 20 -t 120");
}

#define OUT(s) write(mfd, s, sizeof(s)-1)

void MyZDialog::keyPressEvent(QKeyEvent *event)
{
    printf("KEY: %x\n", event->key());
    int err = 0;

    switch (event->key()) {
    case 0x1031: /* Quit */
	if (mfd >= 0) {
	    OUT("quit\n");
	    close(mfd);
	    mfd = -1;
	    sleep(1);
	    if (pid > 0)
		kill(pid, SIGKILL);
	    qApp->quit();
	    return;
	}
	break;
    case 0x1016: /* VolumeUp */
	err = OUT("pausing_keep volume 1\n");
	break;
    case 0x1017: /* VolumeDown */
	err = OUT("pausing_keep volume -1\n");
	break;
    case 0x1014: /* Right i.e. rotated Up */
	if (menu_mode)
	    err = OUT("pausing_keep menu up\n");
	else
	    err = OUT("pausing_keep seek +60\n");
	break;
    case 0x1012: /* Left i.e. rotated Down */
	if (menu_mode)
	    err = OUT("pausing_keep menu down\n");
	else
	    err = OUT("pausing_keep seek -60\n");
	break;
    case 0x1015: /* Down i.e. rotated Right */
	if (menu_mode)
	    err = OUT("pausing_keep menu right\n");
	else
	    err = OUT("pausing_keep seek +10\n");
	break;
    case 0x1013: /* Up i.e. rotated Left */
	if (menu_mode)
	    err = OUT("pausing_keep menu left\n");
	else
	    err = OUT("pausing_keep seek -10\n");
	break;
    case 0x1004: /* Center -> Pause */
	err = OUT("pause\n");
	paused = !paused;
	break;
    case 0x1038: /* LeftSoft -> PgDn */
	if (menu_mode)
	    err = OUT("pausing_keep menu ok\n");
	else
	    err = OUT("pausing_keep seek -600\n");
	break;
    case 0x1030: /* Send -> OSD menu */
	if (menu_mode)
	    err = OUT("pausing_keep menu hide\n");
	else
	    err = OUT("pausing_keep menu main\n");
	menu_mode = !menu_mode;
	break;
    case 0x103a: /* RightSoft -> PgUp */
	if (menu_mode)
	    err = OUT("pausing_keep menu cancel\n");
	else
	    err = OUT("pausing_keep seek +600\n");
	break;
    case 0x1048: /* Music -> Mute */
	err = OUT("pausing_keep mute\n");
	break;
    case 0x1032: /* BS */
	err = OUT("pausing_keep frame_step\n");
	break;
    case 0x1005: /* Internet */
	err = OUT("pausing_keep osd\n");
	break;
    case 0x30:
	break;
    case 0x31:
	err = OUT("pausing_keep sub_delay -0.1\n");
	break;
    case 0x32:
	err = OUT("pausing_keep sub_delay 0.1\n");
	break;
    case 0x33:
	err = OUT("pausing_keep audio_delay -0.1\n");
	break;
    case 0x34:
	err = OUT("pausing_keep audio_delay 0.1\n");
	break;
    case 0x35:
	break;
    case 0x36:
	break;
    case 0x37:
	break;
    case 0x38:
	break;
    case 0x39:
	break;
    case '*':
	break;
    case '#':
	break;
    }

    if (err < 0) {
	if (pid > 0)
	    kill(pid, SIGKILL);
	qApp->quit();
    }
}

void MyZDialog::focusOutEvent(QFocusEvent * event)
{
    printf("FOCUS LOST\n");
    if (!paused) {
	OUT("pausing_keep pause\n");
	paused = 1;
    }
    ZKbMainWidget::focusOutEvent(event);
}

char *file_select(char *dir)
{
	QStringList list;

	dir = strdup(dir);

again:
	chdir(dir);
	list = QString("../");

	DIR * d = opendir(".");
	if (d == NULL)
	    exit(1);

	struct dirent * de;
	while ((de = readdir(d)) != NULL) {
	    struct stat stb;
	    if (de->d_name[0] == '.')
		continue;
	    if (stat(de->d_name, &stb))
		continue;
	    if (S_ISDIR(stb.st_mode)) {
		list += QString::fromUtf8(de->d_name) + QString("/");
	    } else if (S_ISREG(stb.st_mode)) {
		list += QString::fromUtf8(de->d_name);
	    } else {
		continue;
	    }
	}
	closedir(d);
	list.sort();

	ZSingleSelectDlg* dlg = new ZSingleSelectDlg(QString("Z6 MPlayer"),
						     QString::fromUtf8(dir),
						     NULL,
						   "ZSingleSelectDlg", true,
						   0, 0);

	dlg->addItemsList(list);

   	((ZApplication*)qApp)->setMainWidget(dlg);
    	dlg->show();
   	((ZApplication*)qApp)->exec();

	if (dlg->result() != 1)
	    return NULL;

	unsigned int result = dlg->getCheckedItemIndex();
	delete dlg;

	if (result >= list.count())
	    return NULL;

	if (result == 0) {
	    char * p = strrchr(dir, '/');
	    if (p)
		*p = 0;
	    if (dir[0] == 0)
		strcpy(dir, "/");
	    goto again;
	}

	{
	    QString sel = list[result];
	    QCString qc = sel.utf8();
	    char * str = qc.data();
	    /* I am really ignorant, but I have no idea what happens
	     * here when I cancel useless qc and write sel.utf8().data().
	     * Either I do all wrong or gcc is buggy, no idea.
	     */

	    if (str[strlen(str)-1] == '/') {
		char * ndir = (char*)malloc(strlen(dir)+strlen(str)+2);
		sprintf(ndir, "%s/%s", dir, str);
		ndir[strlen(ndir)-1] = 0;
		free(dir);
		dir = ndir;
		goto again;
	    } else {
		char * res = (char*)malloc(strlen(dir)+strlen(str)+2);
		sprintf(res, "%s/%s", dir, str);
		free(dir);
		return res;
	    }
	    goto again;
	}
}

int main(int argc, char **argv)
{
    ZApplication* a = new ZApplication(argc, argv);
    char * mfile;
    int i;
    int faster = 0;
    char * base = NULL;
//    char * tmp  = NULL;
    char * path = "/mmc/mmca1/Programms/MPlayer/bin";
    char * home = "/mmc/mmca1/Programms/MPlayer";
    char ** margs;
//    get_exe_name(tmp);
//    printf("ZZZZZZZZZZZZZZZZZZZZZZZZZZ %s",tmp);
//    sprintf(path,"%s/%s",tmp,"mplayer");

    while ((i = getopt(argc, argv, "+fd:h:p:")) != EOF) {
	switch (i) {
	case 'f':
	    faster = 1;
	    break;
	case 'd':
	    base = optarg;
	    break;
	case 'p':
	    path = optarg;
	    break;
	case 'h':
	    home = optarg;
	    break;
	default:
	    fprintf(stderr, "Usage: z6mplayer [ -d DIR ] [ -- MPLAYER_OPTIONS]\n");
	    exit(-1);
	}
    }

    argc -= optind;
    argv += optind;

    mfile = NULL;
    if (base) {
	mfile = file_select(base);
	if (mfile == NULL) {
	    qApp->quit();
	    delete a;
	    return 0;
	}
    }

    margs = (char**)alloca(sizeof(char*)*(4 + faster*2 + argc));
    i = 0;
    margs[i++] = "mplayer";
    margs[i++] = "-slave";
    if (faster) {
	margs[i++] = "-lavdopts";
	margs[i++] = "fast=1:lowres=1:skiploopfilter=nonkey";
    }
    if (mfile) {
	margs[i++] = mfile;
    }

    while (argc > 0) {
	margs[i++] = argv[0];
	argc--;
	argv++;
    }
    margs[i++] = NULL;


    MyZDialog* dlg = new MyZDialog();
    a->setMainWidget(dlg);
    dlg->show();

    int pfd[2];
    pipe(pfd);
    pid = vfork();
    if (pid == 0) {
	int i;
	dup2(pfd[0], 0);
	for (i=3; i<256; i++)
	    close(i);
	setenv("HOME", home, 1);
	execv(path, margs);
	_exit(127);
    }
    close(pfd[0]);
    mfd = pfd[1];
    signal(SIGPIPE, SIG_IGN);

    a->exec();

    return 0;
}


#include "moc_z6mplayer.cpp"
