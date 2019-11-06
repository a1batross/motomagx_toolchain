/*
# Revision History:
# 
#    date         coreid  description
# ---------------------------------------------------------------------------
#    02-Jun-2008  BeZ     changed return type for functions:
#                            ZListBox::currentItem(), ZListBox::item(int)
#    03-June-2008 BeZ     changed return type for ZListBox::count() from void to int
*/


#ifndef __ZLISTBOX_H_
#define __ZLISTBOX_H_

#include <ZScrollPanel.h>
#include <ZWrapLine.h>

class ZListBox;

/* Size <= 92=23*4 */

class ZListItem
{
    unsigned int data[22];

public:
    ZListItem(ZListBox*, QString);

	enum ListItemType {
	};

    virtual ~ZListItem();
    virtual int getSortText() const;
    virtual int width(ZListBox const*) const;
    virtual int height(ZListBox const*) const;
    virtual int paint(QPainter*);
    virtual int startMarquee();
    virtual int stopMarquee();
    virtual int listitemType() const;

	void check(bool);
	void current() const;
	void drawImage(QPainter*, int, int, int, int, QPixmap const&, int);
	void drawSeparator(QPainter*, int, int, int, int);
	void enabled() const;
	void getItemType() const;
	void getMarkColumnType() const;
	int getReservedData();  //  отсуда получаем указатель на какие то данные, которые сохранили через setReservedData
	void getSelectionState();
	void getZStyle() const;
	bool isChecked() const;
	bool isSelectable() const;
	void partialChecked() const;
	void separatorHeight(ZListBox const*) const;
	void setActive();
	void setEnabled(bool);
	void setPartialChecked(bool);
	void setReservedData(unsigned int); // указатель на данные? котрые будут привязаны к item
	void setSelectable(bool);
	void setSeparator(QString, QPixmap const*);
	void setWrapPolicy(ZWrapLine::WrapPolicy);
	void setZStyle(ZSkinService::WidgetClsID);
	void truncate(QString&, int, unsigned int, QFont&, QString);
	void update(bool);
};

class LBItemInfo;
class LBSubItemInfo;

/* Size 92=23*4 */
 
/*
 * The ZListBoxItem can consist with columns such as:
 *  Icon/IMAGE(%I), MultiLine Text(%M), Separator(%P), Radio box(%R) or Check box(%C)
 
 * There are two kind of ways to express the sub-item
 * a. Text without assign the width %M, the class will calculate the width for it
 * b. Text with special width 80 pixels %M80, the part exceed the width will be invisible
 *
 * @code
 * listBox = new ZListBox( "%M",this );
 *
 * ZListBoxItem* item = new ZListBoxItem(listBox,"%R%M80");
 * item->appendSubItemText(1, "Test text item 1");
 * listBox->insertItem(item); 
*/
class ZListBoxItem: public ZListItem
{
	unsigned int data[23-sizeof(ZListItem)/4];
public: 
	ZListBoxItem(ZListBox*, QString);
	~ZListBoxItem();

	enum ShowPriority {
	};

	// icon line
  void appendSubItem(int index, QPixmap* iconList, unsigned int count);
  //multiline text
  void appendSubItem(int index, QString text, QString text2, QPixmap const* icon, unsigned int, ShowPriority);
  //single line
  void appendSubItem(int index, QString text, bool isWrapable = false, QPixmap const* icon);
  
	void deleteSubItem(int index, int subIndex);
	void drawTextColumn(QPainter*, int, LBItemInfo*, int);
	void getCurrentSubItem(int);
	void getPixmap(int);
	int  getSortText() const;
	void getSubItemIcon(int, int);
  //Get the text of subitem in a multiline text column.
  // index The index of the column, start with 0.
  // subIndex The index of line, start with 0.
	QString getSubItemText(int index, int subIndex, bool text2 = false);
  
	int  height(ZListBox const*) const;
	bool isIndicatorShowed(LBItemInfo*) const;
	bool isShowSubItemIcon() const;
	void keyPressEvent(QKeyEvent*);
	int  listitemType() const;
	void nextShowedSubItem(LBItemInfo*);
	int  paint(QPainter*);
	void prevShowedSubItem(LBItemInfo*);
	void setCurrentSubItem(int, int);
	void setPixmap(int, QPixmap const&);
	void setSortIndex(int, int);
  
	void setSubItem(int, int, QPixmap*, unsigned int);
	void setSubItem(int, int, QString, QString, QPixmap const*, unsigned int);
	void setSubItem(int, int, QString, bool, QPixmap const*);
	void setSubItemShowed(int, int, bool);
  
	void showColumn(int, bool);
	int  startMarquee();
	int  stopMarquee();
	void textColumnItemHeight(ZListBox const*, LBItemInfo*, int) const;
	void textColumnSubItemHeight(ZListBox const*, LBItemInfo*, LBSubItemInfo*, int) const;
	int  width(ZListBox const*) const;
};

class SetItemInfo;
class SetSubItemInfo;

/* Size 92=23*4 */

class ZSettingItem: public ZListItem
{
	unsigned int data[23-sizeof(ZListItem)/4];
public: 
	ZSettingItem(ZListBox*, QString);
	~ZSettingItem();

	enum SettingItemRegion {
	};

	void appendSubItem(int, QString, bool);
	void appendSubItem(int, QString, bool, SettingItemRegion);
	void deleteSubItem(int, int);
	void drawTextColumn(QPainter*, int, SetItemInfo*, int);
	void getPixmap(int);
	int  getSortText() const;
	void getSubItemCount(int);
	QString getSubItemText(int, int);
	int  height(ZListBox const*) const;
	int  listitemType() const;
	int  paint(QPainter*);
	void setPixmap(int, QPixmap const&);
	void setSortIndex(int, int);
	void setSubItem(int, int, QString, bool, SettingItemRegion);
	int  startMarquee();
	int  stopMarquee();
	void textColumnItemHeight(ZListBox const*, SetItemInfo*, int) const;
	void textColumnSubItemHeight(ZListBox const*, SetItemInfo*, SetSubItemInfo*, int) const;
	int  width(ZListBox const*) const;
};


/* Size 268=67*4 */

class ZListBox : public ZScrollPanel
{
	Q_OBJECT
	unsigned int data[67-sizeof(ZScrollPanel)/4];

public:
	enum ITEMALIGN {
	};
	enum ListItemRegion {
    region0,
    region1,
    region2
	};

	virtual int setCurrentItem(int);
        virtual int setCurrentItem(ZListItem*);
        virtual int setTopItem(int);
        virtual int setBottomItem(int);
        virtual int setSelected(ZListItem*, bool);
        virtual int ensureCurrentVisible();

        ZListBox(QString type, QWidget* parent = 0, WFlags f = 0, ZSkinService::WidgetClsID  = ZSkinService::clsZListBox1);
        ZListBox(QWidget* parent = 0, WFlags f = 0, ZSkinService::WidgetClsID  = ZSkinService::clsZListBox1);
	~ZListBox();

	void adjustItems();
	void align(ITEMALIGN) const;
	void changeItem(ZListItem const*, int);
	void checkItem(ZListItem*, bool);
	void checkItem(int, bool);
	void clear();
	void clicked(ZListItem*);
	void clicked(ZListItem*, QPoint const&);
	int count() const;  //changed void to int:    BeZ
	void currentChanged(ZListBoxItem*);
	void currentChanged(ZListItem*);
	void currentChanged(ZSettingItem*);
        int currentItem() const; // change void to int:  BeZ
	void currentRow() const;
	void defaultItemHeight() const;
	void doLayout() const;
	void doubleClicked(ZListItem*);
	void enableEllpsis(bool);
	void enableMarquee(ListItemRegion, bool);
	void firstItem() const;
	void focusInEvent(QFocusEvent*);
	void focusOutEvent(QFocusEvent*);
	int  getCurrentFocusRect(bool) const;
	void getDeleteItemCallBackFunction() const;
	void getEllpsis(ListItemRegion);
	void getImageContainerSkin(ZSkinBase::SelectionState);
	QFont getItemFont(ListItemRegion, bool) const;
	void getItemSkin(ZSkinService::WidgetClsID, ZSkinBase::SelectionState) const;
	void getItemType();
	void getListBoxSpace(ZListItem*) const;
	void getMaxItemWidth() const;
	void getSeparatorFont() const;
	void getSeparatorImage(int) const;
	void getSeparatorSkin(ZSkinService::WidgetClsID) const;
	void getZItemStyle(bool) const;
	int  hasNextPrevFocusItem(bool) const;
	void highlighted(ZListBoxItem*);
	void highlighted(ZListItem*);
	void highlighted(ZSettingItem*);
	void highlighted(int);
	void indImage(ZSkinBase::SelectionState) const;
	void index(ZListItem const*) const;
	void init(QString, QWidget*, unsigned int, ZSkinService::WidgetClsID);
	void insertItem(ZListItem const*, ZListItem const*, bool);
	void insertItem(ZListItem const*, int, bool);
	bool isEnableEllpsis();
	bool isSelected(ZListItem const*) const;
	bool isSelected(int) const;
	bool isShowAllSubItem() const;
	bool isShowSubItemIcon() const;
  ZListBoxItem* item(int) const;  //change void to ZListBoxItem*      :  BeZ
  ZListItem * itemAt(QPoint) const;
	bool itemChecked(ZListItem*);
	bool itemChecked(int);
	void itemFont(ListItemRegion, ZSkinBase::SelectionState) const;
	void itemHeight(int) const;
	void itemRect(ZListItem*) const;
	bool itemVisible(ZListItem const*);
	bool itemVisible(int);
	void itemsChecked();
	void keyPressEvent(QKeyEvent*);
	void markImage(ZSkinBase::SelectionState, bool, bool) const;
	void marqueeEnabled(ListItemRegion) const;
	QSize maxmumSizeHint() const;
	QSize minimumSizeHint() const;
	void mouseDoubleClickEvent(QMouseEvent*);
	void mousePressEvent(QMouseEvent*);
	void moveItem(int, int);
	int numRows() const;
	void radioItemChecked();
	void refreshSlot();
	void removeItem(int);
	int  resetFocusItem(bool);
	void resizeEvent(QResizeEvent*);
	void returnPressed(ZListBoxItem*);
	void returnPressed(ZListItem*);
	void returnPressed(ZSettingItem*);
	void returnPressed(int);
	void rowAt(int) const;
	void selectBtns(ZListItem*);
	void selected(ZListBoxItem*);
	void selected(ZListItem*);
	void selected(ZSettingItem*);
	void selected(int);
	void selectionChanged(ZListBoxItem*);
	void selectionChanged(ZListItem*);
	void selectionChanged(ZSettingItem*);
	void setAlign(ITEMALIGN, int);
	void setCurrentItem(int, bool);
	void setDefaultItemHeight(int);
	void setDeleteItemCallBackFunction(void (*)(ZListItem*));
	void setEllpsis(QString, ListItemRegion);
	void setFontData(QFont&, int, int) const;
	void setItemFont(ListItemRegion, QFont&, bool);
	void setItemFont(ListItemRegion, ZSkinBase::SelectionState, QFont&);
	void setItemType(QString);
	void setListItemType(ZListItem::ListItemType);
	void setPalette(QPalette const&);
	void setSelected(int, bool);
	void setSeparatorFont(QFont&);
	void setShowSubItemIcon(bool);
	void setZBorder(ZWidgetBorderInfo*);
	void setZItemStyle(ZSkinService::WidgetClsID);
	void showAllSubItem(bool);
	void showEvent(QShowEvent*);
	void showedSubItemChanged(int, int);
	QSize sizeHint() const;
	void sort(bool);
	int  takeItem(ZListItem const*);
	void textAlign(ListItemRegion, ZSkinBase::SelectionState);
	void textColor(ListItemRegion, ZSkinBase::SelectionState);
	int topItem() const;
	void triggerUpdate(bool);
	void tryGeometry(int, int) const;
	void updateItem(ZListItem*);
	void updateItem(int);
	void updateSkin(bool);
	int  viewportMouseDoubleClickEvent(QMouseEvent*);
	int  viewportMousePressEvent(QMouseEvent*);
	int  viewportPaintEvent(QPaintEvent*);
};
#endif
