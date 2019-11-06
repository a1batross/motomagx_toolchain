#ifndef __ZGLOBAL_H__
#define __ZGLOBAL_H__ 1

#include <qrect.h>
#include <qwidget.h>

enum EZX_FONT_SIZE_T {
};

namespace ZGlobal
{
    enum PaddingType {
    };
    enum VSpacingType {
    };

	void diffRect(QRect, QRect);
	void getAIAR();
	void getContentR(bool);
	void getCst1_1R();
	void getCst2a_1R();
	void getCst2a_2R();
	void getCst2b_1R();
	void getCst2b_2R();
	void getCst2c_2R();
	void getCst3_1R();
	void getCst3_2R();
	void getCst3_3R();
	void getCst3a_1R();
	void getCst3a_2R();
	void getCst3a_3R();
	void getCst3b_1R();
	void getCst3b_2R();
	void getCst3b_3R();
	void getCst3c_1R();
	void getCst3c_2R();
	void getCst3c_3R();
	void getCst4a_1R();
	void getCst4a_2R();
	void getCst4a_3R();
	void getCst4a_4R();
	void getCst4b_1R();
	void getCst4b_2R();
	void getCst4b_4R();
	void getCstR();
	void getDesktopRect();
	void getDlgA1_1R();
	void getDlgA2a_1R();
	void getDlgA2b_1R();
	void getDlgA3a_1R();
	void getDlgA3a_3R();
	void getDlgA3b_1R();
	void getDlgA3b_3R();
	void getDlgA3c_1R();
	void getDlgA3c_3R();
	void getDlgB1_1R();
	QRect getDlgB2_1R();
	void getDlgCstLR();
	void getDlgCstMR();
	void getDlgCstSR();
	void getDlgLargeConR();
	void getDlgLargeR();
	void getDlgMiddleConR();
	void getDlgSmallConR();
	void getDlgSmallR();
	void getDlgTitleLR();
	void getDlgTitleMR();
	void getDlgTitleSR();
	void getFontSize(EZX_FONT_SIZE_T);
	void getGNBRect();
	void getHeaderR(bool);
	QRect getHomeR(bool);
	void getLineHeight();
	void getLineSpace();
	void getMainWidgetRect();
	void getPadding(PaddingType);
	void getScreenR();
	void getStatusBarR();
	void getSubContentR();
	void getVSpacing(VSpacingType);
	void hideInputWidget(QWidget*);
	QRect mapFromGlobalR(QWidget*, QRect);
	void setInputMethod(QUuid const&, int);
	void showInputWidget(int, int, bool, QUuid const&);
};

#endif
