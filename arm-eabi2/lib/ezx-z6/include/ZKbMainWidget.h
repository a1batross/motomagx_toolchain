#ifndef __ZKBMAINWIDGET_H_
#define __ZKBMAINWIDGET_H_

#include <ZMainWidget.h>
#include <ZHeader.h>

class ZAppInfoArea;
class ZSoftKey;

/* Size: 348=87*4 */

class ZKbMainWidget : public ZMainWidget
{
	Q_OBJECT
	unsigned int data[87 - sizeof(ZMainWidget)/4];

public:
	ZKbMainWidget(QString const&, QWidget*, char const*, unsigned int);
	ZKbMainWidget(QWidget*, char const*, unsigned int);
	ZKbMainWidget(ZHeader::HEADER_TYPE, QWidget*, char const*, unsigned int);
	virtual ~ZKbMainWidget();

	void clearKeyClicked();
	bool event(QEvent*);
	bool eventFilter(QObject*, QEvent*);
	ZAppInfoArea * getAppInfoArea();
	QString getAppTitle();
	int  getLRSBaseIndex();
	QString getMainWidgetTitle();
	void getMainWidgetTitleIcon();
	ZSoftKey * getSoftKey(bool);
	QSize headerSize();
	void init(ZHeader::HEADER_TYPE);
	void isTitleTruncEnable();
	void keyPressEvent(QKeyEvent*);
	void setAppInfoArea(ZAppInfoArea*);
	void setAppTitle(QString const&);
	void setHeaderType(ZHeader::HEADER_TYPE);
	void setMainWidgetTitle(QString const&);
	void setMainWidgetTitleIcon(QPixmap const&);
	bool setSoftKey(ZSoftKey*);
	void setTitleTruncEnable(bool);
	void updateHeader();

public slots:
	void slotAppMessage(QCString const&, QArray<char> const&);
	void slotFullScreenModeChanged(bool);
	void slotKbStateChanged(int, bool);
};

#endif
