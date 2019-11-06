#ifndef __ZMETER_H_
#define __ZMETER_H_

#include <qwidget.h>

class ZMeter : public QWidget
{
  Q_OBJECT
  public:
    ZMeter(QString, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID = ZSkinService::clsZMeter);
    ZMeter(int, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID = ZSkinService::clsZMeter);
    ZMeter(int, int, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID = ZSkinService::clsZMeter);
    ~ZMeter();

    enum Alignment
    { };
    enum Information
    { };
    enum PixmapSetting
    { };
       
    void autoResize() const;
    void drawIndicatorContents(QPixmap&, int, int, QSize);
    int getIndicatorLength() const;
    QSize getIndicatorSize() const;
    void getIndicatorX() const;
    void getIndicatorY() const;
    void maxSize();
    void maxText();
    void meterSizeChange();
    void minText();
    void paintEvent(QPaintEvent*);
    void pause();
    void paused();
    void progress();
    void reset();
    void resizeEvent(QResizeEvent*);
    void running();
    void setAlignment(ZMeter::Alignment);
    void setAutoResize(bool);
    void setEnabled(bool);
    void setInformation(ZMeter::Information);
    void setMaxSize(int);
    void setMaxText(QString);
    void setMinText(QString);
    void setOrientation(Qt::Orientation);
    void setPalette(QPalette const&);
    void setPixmap(QPixmap, QPixmap, ZMeter::PixmapSetting);
    void setProgress(int);
    void setTotalSteps(int);
    void showEvent(QShowEvent*);
    void sizeChanged();
    void totalSteps();
};

/* Size: UNKNOWN */

class ZMeterModule : public QWidget
{
public:
  ZMeterModule(QString, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID = ZSkinService::clsZMeterModule, ZSkinService::WidgetClsID = ZSkinService::clsZMeterModule);
  ZMeterModule(int, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID = ZSkinService::clsZMeterModule, ZSkinService::WidgetClsID = ZSkinService::clsZMeterModule);
  ZMeterModule(int, int, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID = ZSkinService::clsZMeterModule, ZSkinService::WidgetClsID = ZSkinService::clsZMeterModule);
    ~ZMeterModule();

    enum Alignment {
    };

	void autoResize() const;
	void getMeter() const;
	QSize minimumSizeHint() const;
	void paintEvent(QPaintEvent*);
	void resizeAll();
	void resizeEvent(QResizeEvent*);
	void setAlignment(ZMeterModule::Alignment);
	void setAutoResize(bool);
	void setLabelText(QString);
	void setMaxSize(int);
	void setOrientation(Qt::Orientation);
	void setPalette(QPalette const&);
	void setSpacingV1(short);
	void sizeChanged();
	QSize sizeHint() const;
	void updateSkin(bool);
};

#endif
