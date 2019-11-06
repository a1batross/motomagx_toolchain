#ifndef __ZMAINWIDGET_H_
#define __ZMAINWIDGET_H_

#include <ZWidget.h>
#include <qlayout.h>

class QUuid;

/* Size: UNKNOWN, < 348=87*4 */

class ZMainWidget : public ZWidget
{
	Q_OBJECT
	unsigned int data[87 - sizeof(ZWidget)/4];

public:
	ZMainWidget(QWidget*, char const*, unsigned int);
	ZMainWidget(QString const&, bool, QWidget*, char const*, unsigned int);
	ZMainWidget(bool, QWidget*, char const*, unsigned int);
	~ZMainWidget();

        virtual bool setContentWidget(QWidget*);
        virtual QWidget* getCSTWidget(bool);
        virtual int setCSTWidget(QWidget*);
        virtual int setTitleBarWidget(QWidget*);
        virtual int setFullScreenMode(bool, bool);
        virtual int hideInputWidget();
        virtual int slotPopupMenu(int);
        virtual int invokeInputWidget();
        virtual int showToolBar();
        virtual int setToolBar(QUuid const&);
        virtual int hideToolBar();
        virtual int setupInputMethodsPopupMenu();
        virtual int getLRSBaseIndex();

	bool eventFilter(QObject*, QEvent*);
	void fullScreenModeChanged(bool);
	QWidget * getContentWidget(bool);
	bool getEditMode();
	void getFavoriteInputMethods() const;
	bool getFullScreenMode();
	void getKbState();
	QWidget * getTitleBarWidget();
	QVBoxLayout * getVBoxLayout();
	void hide();
	void init(bool, QString const&);
	void kbStateChanged(bool);
	void kbStateChanged(bool, QUuid const&, int);
	void mainWidgetSizeChanged(int, QRect const&);
	void objectDestroyed();
	void paletteChange(QPalette const&);
	void popupKBMenu();
	void setFavoriteInputMethods(QValueList<QUuid> const&);
	void setFavoriteInputMethods(QWidget*, QValueList<QUuid> const&);
	void setInputMethod(QUuid const&, int);
	void setInputMethod(QWidget*, QUuid const&, int, QString);
	void setInputMethods(QWidget*, QUuid const&, QValueList<QUuid> const&, int, QString);
	void setInputMethods(QWidget*, QUuid const&, int, QString);
	void show();
	void showWithInputMethod(QUuid const&, int);

public slots:
	void slotKbStateChanged(bool, QUuid const&, int);
	void slotKbWidgetSizeChanged(QRect const&, int, bool, bool);
};
#endif
