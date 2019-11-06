#ifndef __ZOPTIONMENU_H_
#define __ZOPTIONMENU_H_

#include <ZWidget.h>
#include <qpixmap.h>

class ZOptionsMenu;

/* Size 72=18*4 */

class ZOptionsMenuItem
{
	unsigned int data[18];
public:
	ZOptionsMenuItem(ZOptionsMenu*);
	virtual ~ZOptionsMenuItem();
	virtual void paint(QPainter*, int, int, int, int);
	virtual int calcHeight();

	void setText(QString const&);
};

/* Size: 264=66*4 */

class ZOptionsMenu : public ZWidget
{
	Q_OBJECT
	unsigned int data[66-sizeof(ZWidget)/4];

public:
  ZOptionsMenu(QRect&, QWidget*, char const*, unsigned, ZSkinService::WidgetClsID = ZSkinService::clsZOptionsMenu);
	~ZOptionsMenu ();

	virtual int setActiveItem(int);
	virtual int drawScrollIndicator(QPainter*);


  void aboutToShow();
  void aboutToHide();
  void activated(int);
  void canceled();
  void changeItem(int, QString const&, QPixmap const*);
  void clear();
  void closeEvent(QCloseEvent*);
  void connectItem(int, QObject const*, char const*);
  int count();
  void disabledReason(int) const;
  void disconnectItem(int, QObject const*, char const*);
  void emitSignals();
  void findItem(int, ZOptionsMenu**) const;
  void focusInEvent(QFocusEvent*);
  void focusOutEvent(QFocusEvent*);
  void fontChange(QFont const&);
  int getActiveItemId();
  int getIdFromIndex(int);
  int getIndexFromId(int);
  void initShow();
  void insertItem(ZOptionsMenuItem*, int, int);
  void insertItem(QString const&, ZOptionsMenu*, QPixmap const*, bool, int, int);
  void insertItem(QString const&, QPixmap const*, QObject const*, char const*, bool, bool, bool, int, int);
  void insertSeparator(int, int);
  bool isItemChecked(int) const;
  bool isItemEnabled(int) const;
  void hide();
  bool highlighted(int);
  void keyPressEvent(QKeyEvent*);
  void limitRect() const;
  void lSoftkeyDown();
  void lSoftkeyUp();
  void onShortcut(QKeyEvent*);
  void paintEvent(QPaintEvent*);
  void popup();
  void keyReleaseEvent(QKeyEvent*);
  void removeItem(int, bool);
  void removeItemFromVisibleList(ZOptionsMenu*, ZOptionsMenuItem*);
  void rSoftkeyDown();
  void rSoftkeyUp();
  void setDisabledReason(int, QString const&);
  void setDisabledReasonDlgTitle(int, QString const&);
  void setFixedWidth(int);
  void setItemChecked(int, bool);
  void setItemEnabled(int, bool);
  //void setItemPadding(ZWidgetPaddingInfo const&);
  void setItemSpacing(int);
  void setLimitRect(QRect const&);
  void setPalette(QPalette const&);
  //void setPosition(void CornerE, QPoint&);
  void setSpacing(int);
  void setTextAlignment(Qt::AlignmentFlags);
  void setWrap(bool);
  void show();
  void startMarquee();
  void textAlignment() const;
  void unsetFixedWidth();
  void updateSize();
  void updateVisibleItems(int, bool);
  void wrap() const;
};

#endif
