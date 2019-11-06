#ifndef _ZCONFIG_H_
#define _ZCONFIG_H_

#include <qstring.h>
#include <qstringlist.h>
#include <qmap.h>
class ZConfigData;
typedef QMap< QString, QString > ZConfigGroup;

class ZConfig
{
public:
    ZConfig(QString const& file, bool unk = false); // I don't no, what is bool parametr
    virtual ~ZConfig();

    // No comments =)   
    bool changed() const;
    // May be flush on disk file?
    virtual int flush();

    int write(QString const&);
    // TODO - QString read();
    int parseLine(QString const&);

    int initSettingDirectory();
    QString getSettingDirectory();

    // Make empty group
    int setGroup(QString const&);

    // Return true if group exist in file
    bool groupExists(QString const&);

    // Get list of group names
    void getGroupsKeyList(QStringList&);

    // TODO Iterator(?) getGroupEntriesKeyList(QString const&);
    QMap<QString, ZConfigGroup >::Iterator getGroupEntriesKeyList( const QString& gname );
    
    // Read routines
    bool readBoolEntry(QString const&, QString const&, bool);
    QString readEntryDirect(QString const&, QString const&, QString const&);
    QString readEntry(QString const&, QString const&, QString const&);
    QStringList readListEntry(QString const&, QString const&, QChar const&);
    int readNumEntry(QString const&, QString const&, int);
    unsigned int readUIntEntry(QString const&, QString const&, unsigned int);

    // Write routines
    int writeEntry(QString const&, QString const&, bool);
    int writeEntry(QString const&, QString const&, char*);
    int writeEntry(QString const&, QString const&, double);
    int writeEntry(QString const&, QString const&, int);
    int writeEntry(QString const&, QString const&, QString const&);
    int writeEntry(QString const&, QString const&, QStringList const&, QChar const&);
    int writeEntry(QString const&, QString const&, unsigned int);

    virtual int clearGroup(QString const&);
    virtual int removeEntry(QString const&, QString const&);

protected:

private:
    void* ConfigData;
};

#endif

