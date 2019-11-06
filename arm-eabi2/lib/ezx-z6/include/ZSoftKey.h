#ifndef _ZSOFTKEY_H
#define _ZSOFTKEY_H

#include <ZWidget.h>

class ZOptionsMenu;
class ZSoftButton;
class ZFontInfo;

/* Size 296=74*4 bytes */

class ZSoftKey : public ZWidget
{
	Q_OBJECT

	unsigned int data[74-sizeof(ZWidget)/4];

public:
	virtual QSize sizeHint();

	enum KEY_IDX
	{
		LEFT,
		RIGHT
	};
	enum TEXT_PRIORITY {
	};

	ZSoftKey(QString const&, QWidget*, QWidget*);
	~ZSoftKey();

	void connectKeySignalToSlot(ZOptionsMenu*);
	void connectSubMenuToSlot(ZOptionsMenu*);
	void createBtn();
	void disableClickedSlot(KEY_IDX);
	void enableClickedSlot(KEY_IDX);
	bool eventFilter(QObject*, QEvent*);
	ZOptionsMenu * getOptMenu(KEY_IDX);
	void handleBtnBySK(KEY_IDX, bool, bool);
	void handleDefaultKey();
	void handleShortcutKey(int, bool);
	void handleShortcutKeyOneBtn(int, bool);
	void handleShortcutKeyThreeBtn(int, bool);
	void handleShortcutKeyTwoBtn(int, bool);
	void hideButton(QPainter*, ZSoftButton*);
	void initBtn(QString const&);
	void initFont();
	void isButtonEnabled(KEY_IDX);
	void isButtonShow(KEY_IDX);
	void paintEvent(QPaintEvent*);
	void parseType(QString const&);
	void prevClickedSlot(KEY_IDX);
	void prevResourceID(KEY_IDX);
	void prevText(KEY_IDX);
	void reparent(QWidget*, unsigned int, QPoint const&, bool);
	void resizeEvent(QResizeEvent*);
	void setBgOverlapPixmap(KEY_IDX, QPixmap const&, int);
	void setBtnGeometry();
	void setButtonEnable(KEY_IDX, bool);
	void setClickedSlot(KEY_IDX, QObject const*, char const*);
	void setCstR();
	void setKeyEventWatcher(QWidget*);
	void setOptMenu(KEY_IDX, ZOptionsMenu*);
	void setPalette(QPalette const&);
	void setResourceID(KEY_IDX, QString const&, TEXT_PRIORITY);
	void setText(KEY_IDX, QString const&, TEXT_PRIORITY);
	void setTextForOptMenuHide(QString const&);
	void setTextForOptMenuShow(QString const&, QString const&);
	void setTextSelfShow(int);
	void showButton(KEY_IDX, bool);
	void textForOptMenuHide();
	void textForOptMenuShow(QString&, QString&);
	void updateFont(QFont*, ZFontInfo const&);


public slots:
	void slotBtnClicked(KEY_IDX);
	void slotBtnPressed(KEY_IDX);
	void slotBtnReleased(KEY_IDX);
	void slotLeftKeyPressed();
	void slotLeftKeyReleased();
	void slotMenuHide();
	void slotMenuShow();
	void slotRightKeyPressed();
	void slotRightKeyReleased();
};

#endif
