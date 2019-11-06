#ifndef _ZNUMPICKERDLG_H
#define _ZNUMPICKERDLG_H

#include <ZWidget.h>
#include <ZPopup.h>
#include <ZSpinBox.h>

class ZLabel;

/* Size: UNKNOWN >= 288 */

class ZNumPicker : public ZWidget
{
	Q_OBJECT

	class ZNumPickerData {
	    ZSpinBox *zsb;
	    unsigned int data[2];
	    QPixmap pixmap1;
	    QPixmap pixmap2;
	};

	ZNumPickerData * somedata1;	// 260
	QPixmap somepixmap1;	// 264
	QPixmap somepixmap2;	// 284
	
public:
	ZNumPicker(int, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID);
	~ZNumPicker();

	int  isZEnabled();
	void paintEvent(QPaintEvent*);
	void setEnabled(bool);
	void setPalette(QPalette const&);
	void updateSkin(bool);
	int  isZDisabled();
	void resizeEvent(QResizeEvent*);
	void setLineStep(int);
	void setMaxValue(int);
	void setMinValue(int);
	void setWrapping(bool);
	void valueChange(int);
	void focusInEvent(QFocusEvent*);
	void signalSelect();
	void valueChanged(int);
	void focusOutEvent(QFocusEvent*);
	void keyPressEvent(QKeyEvent*);
	void setAutoResize(bool);
	void keyEventProcess(QEvent*, int);
	QPixmap * getSelectedPixmap();
	QPixmap * getStandardPixmap();
	void setSelectionState(ZSkinBase::SelectionState);
	void numPickerSizeChange();
	QPixmap * getHighSelectedPixmap();
	QPixmap getUpHighSelectedPixmap();
	QPixmap getDownHighSelectedPixmap();
	int  getValue();
	int  lineStep();
	int  maxValue();
	int  minValue();
	void setValue(int);
	void wrapping();
	void autoResize() const;
	QSize minimumSizeHint() const;
	void hasFocus() const;
	QSize sizeHint() const;
};

/* Size: 264=66*4 */

class ZNumModule : public ZWidget
{
	Q_OBJECT
	unsigned int data[66-sizeof(ZWidget)/4];

public:

	enum RelativeAlignment {
	};

	ZNumModule(int, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID);
	~ZNumModule();

	void paintEvent(QPaintEvent*);
	void setPalette(QPalette const&);
	void updateSkin(bool);
	void resizeEvent(QResizeEvent*);
	void setLineStep(int);
	void setMaxValue(int);
	void setMinValue(int);
	void setWrapping(bool);
	void valueChange(int);
	void focusInEvent(QFocusEvent*);
	void valueChanged(int);
	void setAutoResize(bool);
	void numModuleSizeChange();
	int getValue();
	void lineStep();
	int maxValue();
	int minValue();
	void setLabel(ZLabel*, RelativeAlignment);
	void setValue(int);
	void wrapping();
	void getPicker();
	void resizeAll();
	void autoResize() const;
	QSize minimumSizeHint() const;
	QSize sizeHint() const;
};

/* Size 216=54*4 */
 
class ZNumPickerDlg : public ZPopup
{
	Q_OBJECT
	unsigned int data[54-sizeof(ZPopup)/4];

public:
	ZNumPickerDlg(int, QWidget*, char const*, unsigned int);
	~ZNumPickerDlg();

	void initialize(int);
	int getNumValue();
	ZNumModule * getNumModule();

	void keyPressEvent(QKeyEvent*);
public slots:
	int  slotResizeAllChild(int);
	void slotCenterSelKeyPressed();
	void signalCenterSelKeyPressed();
};
#endif
