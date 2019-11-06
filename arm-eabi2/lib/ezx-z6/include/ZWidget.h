#ifndef _ZWIDGET_H
#define _ZWIDGET_H

#include <qwidget.h>
#include <qcstring.h>
#include <qpainter.h>
#include <qpixmap.h>
#include <qstring.h>

#include <ZSkinBase.h>

/* Size 260 = 65*4 */

class ZWidget : public QWidget
{
	Q_OBJECT
        unsigned int data[65 - sizeof(QWidget)/4];

public:
  ZWidget(QWidget* parent = NULL , char const* str = NULL , unsigned type = 0, ZSkinService::WidgetClsID cls = ZSkinService::NONE);
	~ZWidget();

	enum LayoutDirection {
	};

        virtual void updateSkin(bool);
        virtual int getBgImageForTransparent(bool&);
        virtual QSize maxmumSizeHint() const;
        virtual int isScrollPanelTypeWidget() const;
        virtual int isSeparatorTypeWidget() const;
        virtual int getStepInScrollPanel(bool) const;
        virtual int drawBackgroundAndBorder(QPainter&, QRect const*);

	void autoAdjustWidthInPanel() const;
	void cacheTransparentBgImage(bool);
	void drawBackground(QPainter&, QRect const*, bool);
	void drawBorder(QPainter&, QRect const*);
	void fontFamily(int) const;
	QPixmap * getCachedBgPixmap() const;
	void getScreenFSBA();
	void getScreenLayoutDirection() const;
	void getScreenSkinService();
	bool isInternalWidget() const;
	bool isLeftToRightLanguage() const;
	void scrolledInPanel() const;
	void setAutoAdjustWidthInPanel(bool);
	void setInternalWidget(bool);
	void setPalette(QPalette const&);
	void setScreenFSBA(QPixmap&, int, PIXMAP_STRETCH_POLICY_E);
	void setScreenLayoutDirection(LayoutDirection);
	void setScreenSkinFile(QString);
	void setScrolledInPanel(bool);
	QPixmap * transparentBgImageCached() const;
};
#endif
