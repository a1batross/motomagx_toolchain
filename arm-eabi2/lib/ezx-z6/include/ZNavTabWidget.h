//
// C++ Interface: ZNavTabWidget
//
// Description: 
//
//
// Author: root <root@andLinux>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef ZNAVTABWIDGET_H
#define ZNAVTABWIDGET_H

#include "ZWidget.h"
#include <qiconset.h>

class ZNavTabWidget : public ZWidget
{
  public:
    enum TabPosition { top, bottom };
    enum ButtonPos{NEIGHBOR,SEPARATE};
        
    ZNavTabWidget( QWidget *parent = 0, const char *name = 0,
                   const ZSkinService::WidgetClsID clsId = ZSkinService::clsZNavTabWidget);
        
    ZNavTabWidget(int btnPos,bool headerVisible = false,bool b = false,
                  QWidget *parent=0, const char *name=0,
                  const ZSkinService::WidgetClsID clsId = ZSkinService::clsZNavTabWidget);
       
    ~ZNavTabWidget();
    
    void addTab( QWidget *child, const QString &TabTitle);
    void addTab( QWidget *child, const QIconSet &iconset, const QString &TabTitle);
    void setSpacingH1(short spacing);
    void setTabPosition( TabPosition pos);
    
    void showPage( QWidget *w );
    void removePage( QWidget *w );
    QWidget * currentPage() const;
    int currentPageIndex() const;
    void setCurrentPage( int id);
    
  signals:
    void currentChanged( QWidget * );

};    
#endif

