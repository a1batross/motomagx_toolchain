#ifndef __ZHEADER_H_
#define __ZHEADER_H_

#include <ZWidget.h>

/* Size: UNKNOWN */

class ZHeader : public ZWidget
{
public:
	class AppStatusInfo_S
	{
	public:
		AppStatusInfo_S();
		~AppStatusInfo_S();
	};

	enum HEADER_TYPE
	{
		NORMAL_TYPE,
		TIME_TYPE,
		TINY_TYPE,
		FULL_TYPE
	};

	enum HEADER_STATUS {
	};

	ZHeader(HEADER_TYPE, QWidget*, char const*, unsigned int);
	ZHeader(QWidget*, char const*, unsigned int);
	~ZHeader();

	void alignment();
	void changeStatus(HEADER_STATUS, int);
	void getPrimTitle();
	void getSecondTitle();
	void getTitleIcon();
	void headerSize(HEADER_TYPE);
	void init();
	void initStatus(HEADER_TYPE);
	bool isTruncEnable();
	bool isZEnable();
	void paintEvent(QPaintEvent*);
	void primTitleChanged(QString const&);
	void registerInfo(AppStatusInfo_S const&);
	void resizeEvent(QResizeEvent*);
	void secondTitleChanged(QString const&);
	void setAlignment(int);
	void setPalette(QPalette const&);
	void setPrimTitle(QString const&);
	void setSecondTitle(QString const&);
	void setTimeString();
	void setTitleIcon(QPixmap const&);
	void setTruncEnable(bool);
	void slotChangePrimTitle(QString const&);
	void slotChangeSecondTitle(QString const&);
	void slotDisplayTime();
	void slotGetIcon(int);
	void slotPaletteChanged();
	void switchHeader(HEADER_TYPE);
	void unregisterInfo(HEADER_STATUS);
	void updateArea(int);
};

#endif
