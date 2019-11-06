/*
# Revision History:
# 
#    date         coreid  description
# ---------------------------------------------------------------------------
#    02-Jun-2008  BeZ     added scrollbarmode types 
*/

#ifndef __ZSCROLLPANEL_H_
#define __ZSCROLLPANEL_H_

#include <ZWidget.h>

class ZScrollBar;
class ZGroupBox;
class ZMultiLineEdit;
class ZWidgetBorderInfo;

/* Size: 264=66*4*/

class ZScrollPanel : public ZWidget
{ 
    Q_OBJECT
private:
    unsigned int data[66-sizeof(ZWidget)/4];

public:
    
    enum ResizePolicy {  };
    enum ScrollBarMode { Auto, AlwaysOff, AlwaysOn };
    
    ZScrollPanel(QWidget* parent = 0, char const* name = 0, WFlags f=0, ZSkinService::WidgetClsID = ZSkinService::clsZScrollPanel);  
    ~ZScrollPanel();

    
    virtual int removeChild(ZWidget*);
    virtual int addChild(ZWidget* child, int x, int y);
    virtual int moveChild(ZWidget*, int, int);
    virtual void  setVScrollBarMode( ScrollBarMode );
    virtual int setHScrollBarMode(ScrollBarMode);
    virtual int resetFocusItem(bool);
    virtual int getCurrentFocusRect(bool) const;
    virtual int hasNextPrevFocusItem(bool) const;
    virtual int noFocusMode() const;
    virtual int setMargins(int, int, int, int);
    virtual int resizeContents(int, int);
    virtual int setContentsPos(int, int);
    virtual int contentsMousePressEvent(QMouseEvent*);
    virtual int contentsMouseReleaseEvent(QMouseEvent*);
    virtual int contentsMouseDoubleClickEvent(QMouseEvent*);
    virtual int contentsMouseMoveEvent(QMouseEvent*);
    virtual int viewportPaintEvent(QPaintEvent*);
    virtual int viewportResizeEvent(QResizeEvent*);
    virtual int viewportMousePressEvent(QMouseEvent*);
    virtual int viewportMouseReleaseEvent(QMouseEvent*);
    virtual int viewportMouseDoubleClickEvent(QMouseEvent*);
    virtual int viewportMouseMoveEvent(QMouseEvent*);
    virtual int drawContentsOffset(QPainter*, int, int, int, int, int, int);
    virtual int drawContents(QPainter*, int, int, int, int);
    virtual int setResizePolicy(ResizePolicy);
    virtual int setHBarGeometry(ZScrollBar&, int, int, int, int);
    virtual int setVBarGeometry(ZScrollBar&, int, int, int, int);
    virtual int drawContents(QPainter*);


      
	void autoExpandInNestMode() const;
	void bottomMargin() const;
	void center(int, int);
	void center(int, int, float, float);
	void childX(ZWidget*);
	void childY(ZWidget*);
	ZWidget* clipper() const;
	void contentsHeight() const;
	void contentsMoving(int, int);
	void contentsResizing(ZScrollPanel*, int, int);
	void contentsToViewport(QPoint const&);
	void contentsToViewport(int, int, int&, int&);
	void contentsWidth() const;
	void contentsX() const;
	void contentsY() const;
	void editCursorMove(bool);
	void enableClipper(bool);
	void ensureVisible(int, int);
	void ensureVisible(int, int, int, int);
	bool eventFilter(QObject*, QEvent*);
	void firstChild() const;
	void focusAreaBottom() const;
	void focusAreaLeft() const;
	void focusAreaRight() const;
	void focusAreaTop() const;
	bool focusNextPrevChild(bool);
	void focusOutRange() const;
	int  getBgImageForTransparent(bool&);
	void hScrollBarMode() const;
	void hasStaticBackground() const;
	void horizontalScrollBar() const;
	void hslide(int);
	int  isScrollPanelTypeWidget() const;
	void keyPressEvent(QKeyEvent*);
	void keyScrollWrap() const;
	void lastChild() const;
	void leftMargin() const;
	QSize minimumSizeHint() const;
	void moveContents(int, int);
	void nestScrollPanelMode() const;
	void nextChild(ZWidget*) const;
	void prevChild(ZWidget*) const;
	void prevNextWidget(ZWidget*, bool, bool&);
	void repaintContents(QRect const&, bool);
	void repaintContents(int, int, int, int, bool);
	void resize(QSize const&);
	void resize(int, int);
	void resizeEvent(QResizeEvent*);
	void resizePolicy() const;
	void rightMargin() const;
	void scrollBy(int, int);
	void setAutoExpandInNestMode(bool);
	void setEnabled(bool);
	void setFocusArea(int, int, int, int);
	void setFramesWidth(int, int, int, int);
	void setKeyScrollWrap(bool);
	void setMoveFocusOutRange(bool);
	void setNestScrollPanelMode(bool);
	void setPalette(QPalette const&);
	void setStaticBackground(bool);
	void setZBorder(ZSkinBase::BorderPixmaps&);
	void setZBorder(ZWidgetBorderInfo*);
	void show();
	QSize sizeHint() const;
	QSizePolicy sizePolicy() const;
	void styleChange(QStyle&);
	void topMargin() const;
	void updateContents(QRect const&);
	void updateContents(int, int, int, int);
	void updateScrollBars();
	void updateSkin(bool);
	void vScrollBarMode() const;
	void verticalScrollBar() const;
	QWidget* viewport() const;
	void viewportSize(int, int) const;
	void viewportToContents(QPoint const&);
	void viewportToContents(int, int, int&, int&);
	void visibleHeight() const;
	void visibleWidth() const;
	void vslide(int);

public slots:
	void slotContentsResizeTimer();
	void slotContentsResizing(ZGroupBox*, int, int);
	void slotContentsResizing(ZMultiLineEdit*, int, int);
	void slotContentsResizing(ZScrollPanel*, int, int);
};
#endif
