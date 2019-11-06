#ifndef __ZLABEL_H_
#define __ZLABEL_H_

#include <ZWidget.h>
#include <ZWrapLine.h>

/* Size 356=89*4 */

class ZWidgetPaddingInfo;

class ZLabel : public ZWidget
{ 
	Q_OBJECT
	unsigned int data[89 - sizeof(ZWidget)/4];

public:
	enum MarqueeState {
    None = 0,
    Standard,
    Highlighted
	};
	enum MarqueeDirection {
	};
	enum TextDirection {
    LeftToRight = 0,
    RightToLeft
	};

	virtual void setAlignment(Qt::AlignmentFlags);
        virtual void setAutoResize(bool);
        virtual void setText(QString const&);

        ZLabel( QWidget *parent, const char *name=0, WFlags f=0,
                const ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal );
        
        ZLabel( const QString &text, QWidget *parent, const char *name=0,
                WFlags f=0, const ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal);
	
	~ZLabel();

	void adjustHeightBySetting(int);
	void clear();
	void drawOutlineText(QPainter*, QColor, QColor, int, int, int, int, int, QString const&, int, QRect*, char**);
	void fontChange(QFont const&);
	void fontColor() const;
	void getContentNumLines();
	QRect getContentRect();
	void getFrameWidth(int&, int&, int&, int&) const;
	void getTrancatestr(QString const&);
	int  heightForWidth(int) const;
	void isParentBackground();
	bool isZDisabled();
	bool isZEnabled();
	void leading() const;
	void marqueeDirection() const;
	void marqueePause();
	void marqueePlay();
	void marqueeRepetition() const;
	void marqueeSpeed() const;
	void marqueeState() const;
	void marqueeStep() const;
	void numLines() const;
	void paintEvent(QPaintEvent*);
	void preferredWidth() const;
	void resize(int, int);
	void setEnabled(bool);
	void setFontColor(QColor const&);
	void setGeometry(QRect const&);
	void setGeometry(int, int, int, int);
	void setLeading(int);
	void setMarqueeDirection(ZLabel::MarqueeDirection);
	void setMarqueeRepetition(int);
	void setMarqueeSpeed(int);
	void setMarqueeState(ZLabel::MarqueeState);
	void setMarqueeStep(int);
	void setNumLines(int);
	void setOutline(bool, QColor, QColor);
	void setPadding(ZWidgetPaddingInfo const&);
	void setPalette(QPalette const&);
	void setParentBackground(bool);
	void setPreferredWidth(int);
	void setTextDirection(ZLabel::TextDirection);
	void setTruncateNum(int);
	void setTruncateStat(unsigned char);
	void setTruncateString(QString const&);
	void setWrapPolicy(ZWrapLine::WrapPolicy);
	void showEvent(QShowEvent*);
	QSize sizeHint() const;
	void textDirection() const;
	void truncateNum() const;
	void truncateStat() const;
	void truncateString() const;
	void wrapPolicy() const;

};

#endif
