#ifndef _ZPROGRESSDLG_H
#define _ZPROGRESSDLG_H

#include <ZPopup.h>
#include <ZMeter.h>

/* Size: 216=54*4 */

class ZProgressDlg : public ZPopup
{	
	Q_OBJECT
	unsigned int data[54-sizeof(ZPopup)/4];

public:
	ZProgressDlg(QWidget*, char const*, bool, unsigned int);
	ZProgressDlg(QString const&, QString const&, QString const&, QWidget*, char const*, bool, unsigned int);
	ZProgressDlg(QString const&, QString const&, int, QWidget*, char const*, bool, unsigned int);
	ZProgressDlg(QString const&, QString const&, int, int, QWidget*, char const*, bool, unsigned int);
	~ZProgressDlg();

	void autoClose() const;
	void autoReset() const;
	void cancel();
	void cancelled();
	void changeMeter(QString const&);
	void changeMeter(int);
	void changeMeter(int, int);
	void forceShow();
	//void getMeter();
    ZMeter* getMeter();
	//void getMeterModule();
    ZMeterModule* getMeterModule();
	void getMinimumDuration() const;
	void getProgress();
	void getProgressTotalStep();
	void initialize(QString const&, QString const&);
	void keyPressEvent(QKeyEvent*);
	void reset();
	void setAutoClose(bool);
	void setAutoPercentFlag(bool);
	void setAutoReset(bool);
	void setMMAlign(ZMeterModule::Alignment);
	void setMMLabelText(QString const&);
	void setMeterModule(ZMeterModule*);
	void setMinimumDuration(int);
	void setProgress(int);
	void setProgressTotalStep(int);
	bool wasCancelled() const;

public slots:
	void slotLeftSoftKeyClicked();
	int  slotResizeAllChild(int);
};

#endif
