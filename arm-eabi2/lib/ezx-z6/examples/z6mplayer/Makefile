TOOLPREFIX:=	/home/abram/z6/arm-eabi
#TOOLPREFIX:=	/arm-eabi
#Remember to set your own TOOLPREFIX. A to pi3dec bydet!
QTDIR	:=	$(TOOLPREFIX)/lib/qt-2.3.8
EZXDIR	:=	$(TOOLPREFIX)/lib/ezx-z6
UPLOAD_PATH :=  /mmc/mmca1/bin/
CC	=	$(TOOLPREFIX)/bin/arm-linux-gnueabi-gcc
CXX	=	$(TOOLPREFIX)/bin/arm-linux-gnueabi-g++
LD	=	$(TOOLPREFIX)/bin/arm-linux-gnueabi-g++
CFLAGS	=	-pipe -Wall -W -g $(INCPATH)
CXXFLAGS=	-pipe -DQWS -fno-exceptions -fno-rtti -Wall -W -g $(INCPATH)
INCPATH	=	-I$(QTDIR)/include -I$(EZXDIR)/include
LDFLAGS	=	
LDLIBS	=	-L$(TOOLPREFIX)/arm-linux-gnueabi/lib -L$(QTDIR)/lib -L$(EZXDIR)/lib -lm -lqte-mt -lezxpm -ljpeg -lezxappbase -lezxtapi-xscale-r -llog_util -llighting
MOC	=	$(QTDIR)/bin/moc
RM=rm -f
MV=mv

TARGETS = z6mplayer

all: $(TARGETS)

z6mplayer: z6mplayer.o

z6mplayer.o: z6mplayer.cpp moc_z6mplayer.cpp

moc_z6mplayer.cpp: z6mplayer.cpp
	$(MOC) -o $@ $<

install: $(TARGETS)
	ncftpput -u root -p "" 192.168.16.2 $(UPLOAD_PATH) $(TARGETS)

clean:
	$(RM) $(TARGETS)
	$(RM) main
	$(RM) *.o

