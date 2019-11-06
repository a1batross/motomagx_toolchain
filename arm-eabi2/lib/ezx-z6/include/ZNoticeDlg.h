#ifndef _ZNOTICEDLG_H
#define _ZNOTICEDLG_H


#include <ZPopup.h>

/* Size: 216=54*4 */

class ZNoticeDlg : public ZPopup
{ 
	Q_OBJECT
	unsigned int data[54-sizeof(ZPopup)/4];

public: 
	/*
  enum Type
	{
		notice, exclamation, nothing,
	};
  */
  enum Type
  {
    Success,           
    Information        
  };  
  
	ZNoticeDlg(ZNoticeDlg::Type type, QString const &instructText, QString const &strMsg, QWidget* parent, char const* name, bool modal, unsigned flag, bool dismisTimer);
	ZNoticeDlg(ZNoticeDlg::Type type, unsigned timeout_ms, QString const&, QString const&, QWidget*, char const*, bool, unsigned);
	~ZNoticeDlg();

	void dismissDlg(ZPopup::PopupCode);
	void initialize(ZNoticeDlg::Type);
	void setAnimate(QString const&);
	static int information(QString const&, QString const&, QString const&, QString const&, QObject const*, char*);
	void slotTimeout();
	void dlgDismissed();
	void keyPressEvent(QKeyEvent*);
	void setMessageIcon(QPixmap const&);
	void setMessageText(QString const&);
	void setAutoDismissTime(int);
	int  slotResizeAllChild(int);
	void calculateDismissTime();
	void startAutoDismissTimer();
	void showEvent(QShowEvent*);
};

#endif
