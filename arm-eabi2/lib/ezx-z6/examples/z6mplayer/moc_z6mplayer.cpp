/****************************************************************************
** MyZDialog meta object code from reading C++ file 'z6mplayer.cpp'
**
** Created: Wed Aug 13 18:30:35 2008
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.8   edited 2004-08-05 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *MyZDialog::className() const
{
    return "MyZDialog";
}

QMetaObject *MyZDialog::metaObj = 0;

#ifdef QWS
static class MyZDialog_metaObj_Unloader {
public:
    ~MyZDialog_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "MyZDialog" );
    }
} MyZDialog_metaObj_unloader;
#endif

void MyZDialog::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(ZKbMainWidget::className(), "ZKbMainWidget") != 0 )
	badSuperclassWarning("MyZDialog","ZKbMainWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString MyZDialog::tr(const char* s)
{
    return qApp->translate( "MyZDialog", s, 0 );
}

QString MyZDialog::tr(const char* s, const char * c)
{
    return qApp->translate( "MyZDialog", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* MyZDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) ZKbMainWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"MyZDialog", "ZKbMainWidget",
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}
