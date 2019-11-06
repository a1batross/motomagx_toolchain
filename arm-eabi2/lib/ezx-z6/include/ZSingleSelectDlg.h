#ifndef _ZSINGLESELECTDLG_H
#define _ZSINGLESELECTDLG_H

#include <ZPopup.h>

class ZListBox;

/* Size:216=54*4 */

class ZSingleSelectDlg : public ZPopup
{	
	Q_OBJECT
	unsigned int data[54-sizeof(ZPopup)/4];
public: 
	ZSingleSelectDlg(QWidget*, char const*, bool, unsigned int);
	ZSingleSelectDlg(QString const&, QString const&, QWidget*, char const*, bool, unsigned int, int);
	~ZSingleSelectDlg();

	ZListBox* getListBox();
	void initialize();
	bool eventFilter(QObject*, QEvent*);
	void addItemsList(QStringList&);
	int getCheckedItem();
	int getCheckedItemIndex();
	int checkCurHighlightItem();
	void showEvent(QShowEvent*);

public slots:
	int slotLSKClicked();
	int slotResizeAllChild(int);
signals:
	void signalCenterSelKeyPressed();
};
#endif
