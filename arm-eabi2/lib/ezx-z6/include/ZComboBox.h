#ifndef _ZCOMBOBOX_H
#define _ZCOMBOBOX_H

class QValidator;
class ZListBoxItem;

#include <ZWidget.h>
#include <ZButton.h>

/* Size: <=324=81*4 */

class ZComboBox : public ZButton
{
	Q_OBJECT
	unsigned int data[81 - sizeof(ZButton)/4]; 

public:
	enum Policy {
	};

	virtual QRect getContentRect() const;
        virtual int getBtnFrameWidth(int&, int&, int&, int&) const;
        virtual int getLabelFrameWidth(int&, int&, int&, int&) const;
        virtual int getFrameWidth(int&, int&, int&, int&) const;
        virtual int drawBorderEx(ZButton::ItemType, QPainter*, QRect const*);
        virtual int drawBackgroundEx(ZButton::ItemType, QPainter*, QRect const*);
        virtual int getBtnHSpacing() const;
        virtual int getTitleSpacing(ZButton::TitlePosition) const;
        virtual int stateChanged(ZButton::StateChangeReason);
        virtual void titleChanged(QString const&);
        virtual int getCurrentFont(QFont&, QColor&, ZButton::ItemType) const;

        virtual void setCurrentItem(int);
        virtual void setSizeLimit(int);
        virtual int setMaxCount(int);
        virtual int setInsertionPolicy(ZComboBox::Policy);
        virtual int setValidator(QValidator const*);
        virtual int setAutoCompletion(bool);
        virtual int slotLeftSoftkeyClick();
        virtual int slotRightSoftkeyClick();

	enum DlgType {
		NONE,
		TEXT
	};

	ZComboBox(QWidget*, char const*, bool);
	ZComboBox(bool, QWidget*, char const*, bool);
	~ZComboBox();

	void activated(QString const&);
	void activated(int);
	void autoCompletion() const;
	void changeItem(QPixmap const&, QString const&, int);
	void changeItem(QPixmap const&, int);
	void changeItem(QString const&, int);
	void clear();
	void clearValidator();
	void count() const;
	int currentItem() const;
	QString currentText() const;
	void customEvent(QCustomEvent*);
	void duplicatesEnabled() const;
	void editable() const;
	void getItemType(ZListBoxItem*) const;
	void highlighted(QString const&);
	void highlighted(int);
	void insertItem(QPixmap const&, QString const&, int);
	void insertItem(QPixmap const&, int);
	void insertItem(QString const&, int);
	void insertStrList(QStrList const&, int);
	void insertStrList(QStrList const*, int);
	void insertStrList(char const**, int, int);
	void insertStringList(QStringList const&, int);
	void insertZItem(QPixmap const&, QString const&, int, int);
	void insertZItem(QPixmap const&, int, int);
	void insertZItem(QString const&, int, int);
	void insertionPolicy() const;
	void keyPressEvent(QKeyEvent*);
	void lineEdit() const;
	void listBox() const;
	void maxCount() const;
	void pixmap(int) const;
	void popup(bool);
	void removeItem(int);
	void resize(QSize const&);
	void resize(int, int);
	void resizeEvent(QResizeEvent*);
	void setDlgInstructText(QString const&, DlgType);
	void setDlgTitle(QString const&, DlgType);
	void setDuplicatesEnabled(bool);
	void setEditable(bool);
	void setGeometry(QRect const&);
	void setGeometry(int, int, int, int);
	void setPalette(QPalette const&);
	void setSoftkeyText(QString const&, QString const&, DlgType);
	void setSoftkeyTextLeft(QString const&, DlgType);
	void setSoftkeyTextRight(QString const&, DlgType);
	void showEvent(QShowEvent*);
	void sigInsertData(QWidget*, bool);
	void sizeLimit() const;
	void slotClearKeyClick();
	void styleChange(QStyle&);
	void text(int) const;
	void textChanged(QString const&);
	void updateSkin(bool);
	void validator() const;
};

#endif

