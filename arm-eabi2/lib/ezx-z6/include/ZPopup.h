#ifndef _ZPOPUP_H
#define _ZPOPUP_H

#include <qdialog.h>
#include <ZSkinBase.h>

class ZSoftKey;
class ZDetailView;
class ZFormContainer;
class ZIconView;
class ZWidgetBorderInfo;
class ZWidgetPaddingInfo;
class ZScrollPanel;
class ZWidget;

/* Size <= 228=57*4 bytes, 216=54*4 */

class ZPopup : public QDialog
{
    Q_OBJECT
    unsigned int data[54 - sizeof(QDialog)/4];

public:
    enum PopupCode {
    };

    virtual void done(int);
    virtual void accept();
    virtual void reject();

    virtual int doLayout();

    enum POPUP_TYPE_E {
    };

    ZPopup(ZPopup::POPUP_TYPE_E, QWidget*, char const*, bool, int, unsigned int);
    ~ZPopup();

	ZSoftKey * getSoftKey();
	void setPalette(QPalette const&);
	void timerEvent(QTimerEvent*);
	void applyBodyBk();
	void customEvent(QCustomEvent*);
	void insertChild(ZDetailView*, int);
	void insertChild(ZFormContainer*, int);
	void insertChild(ZWidget*, int);
	void insertChild(ZIconView*, int);
	void removeChild(ZWidget*);
	void layoutDialog();
	void layoutNotice();
	void layout_inner(int, int);
	void loadSkinData(bool);
	void setTitleIcon(QPixmap const&);
	void setTitleIcon(QString const&);
	void applySkinData();
	void detect_xModal();
	void getScrollable();
	void keyPressEvent(QKeyEvent*);
	void layoutListbox();
	void layoutNothing();
	void setBodyBorder(ZWidgetBorderInfo*);
	void setBodyBorder(ZSkinBase::BorderPixmaps&);
	void setScrollable(bool);
	void getAppInfoArea();
	void getPopupHeader();
	void layoutIconView();
	void setBodyPadding(ZWidgetPaddingInfo const&);
	void setSoftkeyText(QString const&, QString const&);
	void slotSPC_resize(ZScrollPanel*, int, int);
	void askReturnToIdle(int);
	void postLayoutEvent();
	void removeAndInsert();
	void setBodyVSpacing(int);
	void setInstructFont(QFont const&);
	void setInstructText(QString const&);
	void layoutDetailView();
	void layoutScrollPanel();
	void releaseBodyPixmap();
	void setBodyBackground(QPixmap&);
	void setInsTruncPolicy(bool);
	void leftSoftkeyClicked();
	void setAutoDismissTime(int);
	void setInstructPadding(ZWidgetPaddingInfo const&);
	void setSoftkeyTextLeft(QString const&);
	void getChildrenMaxWidth();
	void layoutFormContainer();
	void rightSoftkeyClicked();
	void setInsLabelProperty(bool);
	void setReturnIdlePolicy(int, bool);
	void setSoftkeyTextRight(QString const&);
	void layoutNoticeTwoAreas();
	void setInstructFontColor(QColor const&);
	void updateIdleScreenSign();
	void layoutDialogFourAreas();
	void signalClearKeyPressed();
	void getBodyAvailableHeight();
	void calculateDesiredContentHeight(int);
	void show();
	void getTitle();
	void setTitle(QString const&);
	void enableAia(bool);
	void hideEvent(QHideEvent*);
	void showEvent(QShowEvent*);
	void isNeedShowVScrollBar() const;
	void getBodyAvailableWidth() const;
	void calculateBodyAvailWidth(bool) const;
	void getBody() const;


public slots:
    virtual int    slotLSKClicked();
    virtual int    slotRSKClicked();
    virtual int    slotKbStateChanged(int, bool);
    virtual int    slotResizeAllChild(int);
};

#endif
