#ifndef _ZSKINBASE_H_
#define _ZSKINBASE_H_ 1

enum PIXMAP_STRETCH_POLICY_E
{
	NONE = 0
};

class ZSkinBase
{
public:
    enum RelativeAlignment {
    };
    enum SelectionState {
    };
    enum BorderPixmaps {
    };

    virtual ~ZSkinBase();
};

class ZSkinService
{
public:
  // this enum from E2 !!!!
  enum WidgetClsID
  {
    clsZAlternatesChooser,
    clsZAlternatesItem,
    clsZAlternatesList,
    clsZAppInfoArea,
     
    clsZCalendarModule,
    clsZCalendarModule_Day,
    clsZCalendarModule_CurDay,
    clsZCalendarModule_DayHeader,
    clsZCalendarModule_CurDayHeader,
    clsZCalendarModule_EmptyDay,
    clsZCalendarModule_Grid,
       
    clsZCheckBox,
    clsZColorModule,
    clsZColorModule_Cname,
    clsZColorModule_Well,
    clsZColorPicker,
    clsZColorPicker_Well,
    clsZComboBox,
    clsZDateModule,
    clsZTimeModule = clsZDateModule,
    clsZNumModule = clsZDateModule,
    clsZDatePicker,
    clsZTimePicker = clsZDatePicker,
    clsZNumPicker = clsZDatePicker,
    clsZExhibitButton,
    clsZFiveWayButton1,
    clsZFiveWayButton2,
    clsZFormContainer,
    clsZFormItem,
    clsZGroupBox,
    clsZHeader1,
    clsZHeader2,
    clsZHeader3,
    clsZHeader4,
    clsZHeaderPopup,  
    clsZIconView1,
    clsZIconView2,
    clsZIconViewItem1,
    clsZIconViewItem2,
    clsZInputMatrix,
    clsZInteractiveHighlight,
    clsZJumpBox,
    clsZJumpBox_Field,
    clsZLineEdit,
    clsZListBox1,
    clsZSettingView1 = clsZListBox1,
    clsZListBox2,
    clsZSettingView2 = clsZListBox2,
    clsZListItem1,
    clsZListItem2,
    clsZMatrixItem,
    
    clsZMeter,
    clsZMeter_Indicator1,
    clsZMeter_Indicator2,
    clsZMeter_Indicator3,
    clsZMeter_Indicator4 = clsZMeter_Indicator3,  //same as indicator3, just change a pixmap for animation
    
    clsZMeterModule,
    clsZSliderModule = clsZMeterModule,
    clsZProgressSliderModule = clsZMeterModule,
    clsZMultiLineEdit1,
    clsZMultiLineEdit2,    
    clsZNavTabWidget,
    clsZNavTabWidget_TabArea,
    clsZOptionsMenu,
    clsZOptionsMenuItem,
    clsZPanel1,
    clsZPanel2,
    clsZPopup1,
    clsZPopup2,          
//      clsZPopup3,
    clsZPressButton,
    clsZRadioButton,
    clsZScrollPanel,
    clsZScrollView = clsZScrollPanel,
    clsZSegmentField,
    clsZSeparator1,
    clsZSeparator2,
    clsZSettingItem,
    clsZSlider,
    clsZProgressSlider = clsZSlider,
    clsZSoftKeyLeft,
    clsZSoftKeyRight,
    clsZSoftKeyMiddle,     
    clsZSplitPane,
    
    clsZDetailView1,
    clsZDetailView2,
    clsZDetailItem,
    clsZImageContainer,
    clsZImageContainer1,
    clsZImageContainer2,
    //clsZImageContainer4,
    clsZMediaControl,
    clsZScrollbar,
    clsZScrollbar_Input,
    clsZScrollbar_Field,
    clsZStructDataImage,
    clsZFsba1,
    clsZFsba2,
    
    clsMax = clsZFsba2,
    clsTotal = clsMax + 1,
    NONE = 0
  };
  
};


#endif
