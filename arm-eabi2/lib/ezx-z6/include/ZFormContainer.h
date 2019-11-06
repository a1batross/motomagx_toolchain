#ifndef _ZFORMCONTAINER_H
#define _ZFORMCONTAINER_H

#include <qstring.h>
#include <qwidget.h>
#include <ZWidget.h>
#include <ZScrollPanel.h>

/* Size 268=67*4 */ 

class ZFormContainer : public ZScrollPanel
{ 
	Q_OBJECT
	unsigned int data[67-sizeof(ZScrollPanel)/4];
public:
	ZFormContainer(QWidget*, unsigned int, ZSkinService::WidgetClsID);
	~ZFormContainer();

	void setPalette(QPalette const&);
	void updateSkin(bool);
	void eventFilter(QObject*, QEvent*);
	void removeChild(ZWidget*);
	void resizeEvent(QResizeEvent*);
	void triggerUpdate(bool);
	void maxmumSizeHint();
	void slotLayoutTimer();
	void addChild(ZSeparator*, bool);
	void addChild(ZMultiLineEdit*, bool);
	void addChild(ZWidget*, bool);
	void addChild(ZFormItem*, bool);
	void addChild(ZGroupBox*, bool);
	void doLayout();
	void showEvent(QShowEvent*);
};
#endif
