#ifndef _ZCHECKBOX_H
#define _ZCHECKBOX_H

#include <ZBaseButton.h>
#include <ZSkinBase.h>

/* Size: 284=71*4 */

class ZCheckBox: public ZBaseButton
{
	Q_OBJECT
	unsigned int data[71 - sizeof(ZBaseButton)/4];
public:
	enum TitlePosition {
	};

	ZCheckBox(QWidget*, char const*);
	ZCheckBox(QString const&, QWidget*, char const*);
	~ZCheckBox();

	void drawButton(QPainter*);
	void setEnabled(bool);
	void setPalette(QPalette const&);
	void setSpacing(int, int);
	void updateSkin(bool);
	void resizeEvent(QResizeEvent*);
	void setGeometry(QRect const&);
	void setGeometry(int, int, int, int);
	void setNoChange();
	void setTristate(bool);
	void focusInEvent(QFocusEvent*);
	void focusOutEvent(QFocusEvent*);
	void keyPressEvent(QKeyEvent*);
	void keyReleaseEvent(QKeyEvent*);
	void setTitlePosition(ZCheckBox::TitlePosition);
	void setGroupAlignment(Qt::AlignmentFlags);
	void setFormItemSpacing(int);
	void setSkinFocusEffect(QFocusEvent*);
	void setRelativeAlignment(ZSkinBase::RelativeAlignment);
	void resize(int, int);
	void setTitle(QString const&);
	void setPixmap(QPixmap const&);
	int  isTristate() const;
	int  isZEnabled() const;
	void isZDisabled() const;
	QRect getTitleRect() const;
	void getTitleSize() const;
	void getFrameWidth(int&, int&, int&, int&) const;
	void titlePosition() const;
	QRect getContentRect() const;
	void groupAlignment() const;
	int  heightForWidth(int) const;
	QRect getCheckBtnRect() const;
	void relativeAlignment() const;
	void title() const;
	QPixmap * pixmap() const;
	QSize sizeHint() const;
};

#endif
