#ifndef _ZBASEBUTTON_H
#define _ZBASEBUTTON_H 1

class ZBaseButtonGroup;

#include <ZFormItem.h>
#include <ZSkinBase.h>

/* Size: UNKNOWN >= 276=69*4 */

class ZBaseButton : public ZFormItem
{
    Q_OBJECT
    unsigned int data[68 - sizeof(ZFormItem)/4];
    /* Flags are at offset 272 */
    unsigned int state;

public:

    enum ToggleType {
    };
    enum ToggleState {
	off, middle, on
    };

    /* Yup, this "useful" function is inline. */
    ToggleState getState() {
	return (ToggleState)((state>>3) & 3);
    }
  
    virtual int setText(QString const&);
    virtual void setPixmap(QPixmap const&);
    virtual int setAccel(int);
    virtual int setDown(bool);
    virtual int setAutoResize(bool);
    virtual int setAutoRepeat(bool);
    virtual int setToggleType(ZBaseButton::ToggleType);
    virtual int setState(ZBaseButton::ToggleState);
    virtual int hitButton(QPoint const&) const;
    virtual void drawButton(QPainter*);
    virtual int drawButtonLabel(QPainter*);
    virtual int setGroup(ZBaseButtonGroup*);

	ZBaseButton(QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID);

	void accel() const;
	void animateClick();
	void animateTimeout();
	void autoRepeatTimeout();
	void clicked();
	void enabledChange(bool);
	void ensureData();
	void focusInEvent(QFocusEvent*);
	void focusOutEvent(QFocusEvent*);
	void group() const;
	void isExclusiveToggle() const;
	void keyPressEvent(QKeyEvent*);
	void keyReleaseEvent(QKeyEvent*);
	void mouseMoveEvent(QMouseEvent*);
	void mousePressEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);
	void nextState();
	void paintEvent(QPaintEvent*);
	void pressed();
	void released();
	void stateChanged(int);
	void timer();
	void toggle();
	void toggled(bool);
};

#endif
