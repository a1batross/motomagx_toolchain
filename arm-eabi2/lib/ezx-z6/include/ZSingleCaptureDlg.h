/*
# Revision History:
# 
#    date         coreid  description
# ---------------------------------------------------------------------------
#    02-Jun-2008  BeZ     changed return type for functions:
#                            ZSingleCaptureDlg::getLineEdit()
*/

#ifndef _ZSINGLECAPTUREDLG_H
#define _ZSINGLECAPTUREDLG_H

#include <ZPopup.h>
//
#include <ZLineEdit.h>
#include <ZMultiLineEdit.h>

/* Size:216=54*4 */

class ZSingleCaptureDlg : public ZPopup
{
	Q_OBJECT
	unsigned int data[54 - sizeof(ZPopup)/4];
public: 
	enum CaptureDlgType
	{
		normal, secret, normal2, secret2 
	};
	ZSingleCaptureDlg(QString const&, QString const&, ZSingleCaptureDlg::CaptureDlgType, QWidget*, char const*, bool, unsigned int, int);
	ZSingleCaptureDlg(QWidget*, char const*, bool, unsigned int);
	~ZSingleCaptureDlg();

	void initialize(ZSingleCaptureDlg::CaptureDlgType);
	int getDialogType();
  ZWidget* getEditWidget();
  ZWidget* getLineEdit();
  ZWidget* getMultiLineEdit();
  QString getResultText();
	
  void setEditWidget(ZWidget*);


public slots:
	int  slotLSKClicked();
	int  slotRSKClicked();
	int  slotResizeAllChild(int);
};

#endif
