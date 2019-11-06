/*
# Revision History:
# 
#    date         coreid  description
# ---------------------------------------------------------------------------
#    02-Jun-2008  BeZ     changed return type for functions:
#                            ZDetailItem::paint(), ZDetailItem::height() 
*/

#ifndef _ZDETAILVIEW_H
#define _ZDETAILVIEW_H

#include <ZScrollPanel.h>
#include <ZWrapLine.h>


class QPainter;
class ZDetailView;

class ZDetailItem
{
public:

    enum FontType {
    };
    enum ColorType {
    };

    virtual ~ZDetailItem();
    virtual int paint(QPainter&);
    virtual int height(ZDetailView const*);

	ZDetailItem(QString, QPixmap*, ZDetailView*);
	ZDetailItem(ZDetailItem::ItemType, QString, QChar, ZDetailView*);

	void clearAllRow();
	void setCurrentSD(int);
	void setParseType(QString);
	void getReservedData();
	void separatorHeight(ZDetailView const*);
	void setReservedData(unsigned int);
	void enableTitleParse(bool);
	void appendTextIconRow(QString);
	void appendTextIconRow(QString, QPixmap&, bool);
	void appendTextIconRow(QPixmap&);
	void enableStructureDataParse(bool);
        int paint(QPainter*) const; //change void to int   :   BeZ
        int height(ZDetailView const*) const; //change void to int   :   BeZ
	void doParse();
	void setRect(int, int, int, int);
	void setDirty(bool);
	void removeRow(unsigned int);
	void setParent(ZDetailView*);
	void setFont(ZDetailItem::FontType, QFont&);
	void getSDCount() const;
	void currentSDIndex() const;
	void rect() const;
	void dirty() const;
	void itemType() const;
	void getSDData(int, QString&, QString&, QString&) const;
	void getSDRect(int) const;
	void font(ZDetailItem::FontType) const;
	void color(ZDetailItem::ColorType) const;

};

/* Size: UNKNOWN*/

class ZDetailView : public ZScrollPanel
{
    Q_OBJECT

public:
	void removeItem(ZDetailItem*);
	void setPalette(QPalette const&);
	void updateItem(ZDetailItem*);
	void updateSkin(bool);
	void highlighted(ZDetailItem const*, QString const&, QString const&, QString const&);
	void insertIntem(ZDetailItem*, ZDetailItem*);
	void refreshSlot();
	void resizeEvent(QResizeEvent*);
	void focusInEvent(QFocusEvent*);
	void setCurrentSD(int, bool);
	void focusOutEvent(QFocusEvent*);
	void keyPressEvent(QKeyEvent*);
	void returnPressed(ZDetailItem const*, QString const&, QString const&, QString const&);
	void setWrapPolicy(ZWrapLine::WrapPolicy);
	void triggerUpdate(bool);
	void resetFocusItem(bool);
	void getStructureData(int, QString&, QString&, QString&);
	void viewportPaintEvent(QPaintEvent*);
	void ensureCurrentVisible();
	void setStructureDataParser(ZStructureDataParser*);
	void addItem(ZDetailItem*);
	void setFont(ZDetailItem::FontType, QFont&);
	void showEvent(QShowEvent*);
	void ZDetailView(QWidget*, unsigned int, ZSkinService::WidgetClsID);
	void ~ZDetailView();
	void getSDCount() const;
	void isOutlined() const;
	void wrapPolicy() const;
	void getItemSkin() const;
	void noFocusMode() const;
	void setFontData(QFont&, int, int) const;
	void outlinedSize() const;
	void outlinedColor() const;
	void currentSDIndex() const;
	void maxmumSizeHint() const;
	void getMaxItemWidth() const;
	void getSeparatorFont() const;
	void getSeparatorSkin() const;
	void getSeparatorImage(int) const;
	void getCurrentFocusRect(bool) const;
	void getStepInScrollPanel(bool) const;
	void hasNextPrevFocusItem(bool) const;
	void getStructureDataParser() const;
	void font(ZDetailItem::FontType) const;
	void color(ZDetailItem::ColorType) const;
	void current() const;
	void doLayout() const;
	void itemRect(ZDetailItem*) const;
	void getSDRect(int) const;
	void wrapSpace() const;
};

#endif
