#ifndef _ZBUTTON_H
#define _ZBUTTON_H 1

#include <ZBaseButton.h>
#include <ZSkinBase.h>

class ZButton : public ZBaseButton
{
    Q_OBJECT

public:
    virtual int text() const;
    virtual int setNum(int);
    virtual int pixmap() const;

    enum ItemType {
    };
    enum TitlePosition {
    };
    enum StateChangeReason {
    };
    enum MarqueeDirect {
    };

	virtual QRect getContentRect() const = 0;
        virtual int getBtnFrameWidth(int&, int&, int&, int&) const = 0;
        virtual int getLabelFrameWidth(int&, int&, int&, int&) const = 0;
        virtual int getFrameWidth(int&, int&, int&, int&) const = 0;
        virtual int drawBorderEx(ZButton::ItemType, QPainter*, QRect const*) = 0;
        virtual int drawBackgroundEx(ZButton::ItemType, QPainter*, QRect const*) = 0;
        virtual int getBtnHSpacing() const = 0;
        virtual int getTitleSpacing(ZButton::TitlePosition) const = 0;
        virtual int stateChanged(ZButton::StateChangeReason) = 0;
        virtual void titleChanged(QString const&) = 0;
        virtual int getCurrentFont(QFont&, QColor&, ZButton::ItemType) const = 0;

	ZButton(QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID);
	ZButton(QString const&, ZButton::TitlePosition, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID);
	~ZButton();

	void drawButton(QPainter*);
	int isZEnabled();
	void setEnabled(bool);
	int isZDisabled();
	void resizeEvent(QResizeEvent*);
	void focusInEvent(QFocusEvent*);
	void reAdjustSize(bool, int, int);
	void enableMarquee(bool);
	void focusOutEvent(QFocusEvent*);
	void keyPressEvent(QKeyEvent*);
	int drawButtonLabel(QPainter*);
	void isEnableMarquee();
	void keyReleaseEvent(QKeyEvent*);
	void enableTruncation(bool);
	void getMarqueeDirect();
	void setMarqueeDirect(MarqueeDirect);
	void setTitlePosition(TitlePosition);
	void setAvailableWidth(int);
	void isEnableTruncation();
	void setRelativeAlignment(ZSkinBase::RelativeAlignment);
	void setFont(QFont const&);
	int setText(QString const&);
	void setTitle(QString const&);
	void setPixmap(QPixmap const&);
	void getBtnRect() const;
	void getBtnSize() const;
	void getTitleRect() const;
	void getTitleSize() const;
	void getBtnContentRect() const;
	QSize sizeHint() const;


};

#endif
