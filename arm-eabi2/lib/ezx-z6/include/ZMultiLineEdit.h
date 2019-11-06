#ifndef _ZMULTILINEEDIT_H_
#define _ZMULTILINEEDIT_H_

#include <ZTableView.h>
#include <qpoint.h>

class QValidator;
class TsGlyphInfo;
class TsLayoutInfo;
class TsLayout_;
class QFont;
class ZFontInfo;
class QEvent;
class ZMultiLineEditCommand;

enum TsBidiCharClass {
};

/* Size: 504=126*4 */

class ZMultiLineEdit : public ZTableView
{
    Q_OBJECT
    unsigned int data[126-sizeof(ZTableView)/4];

public:
    enum InsertionMethod {
      atEnd,            // after text insert cursor return to end of text
      atHome,           // after text insert cursor return to end of text
      atPosSelected,    // after text insert cursor return to end of text
      atPosNoSelected   // after text insert cursor return to end of text
    };
    enum EchoMode {
      Normal,
      NoEcho,
      Password
    };
    enum TextType {
    };
    enum CursorFlagDirection {
    };
    enum TitlePosition {
    };
    enum WordWrap {
      NoWrap,
      WidgetWidth,
      FixedPixelWidth,
      FixedColumnWidth
    };
    enum ZWrapPolicy {
      AtWhiteSpace,
      Anywhere
    };

    virtual void insertLine(QString const&, int);
    virtual void insertAt(QString const&, int, int, bool);
    virtual void removeLine(int);
    virtual void setCursorPosition(int line, int col, bool mark=FALSE); // Sets the cursor position to character number col in line number line. The parameters are adjusted to lie within the legal range.If mark is FALSE, the selection is cleared. otherwise it is extended
    virtual void setFixedVisibleLines(int); //Sets the fixed height of the QMultiLineEdit so that lines text lines are visible given the current font.
    virtual void setValidator(QValidator const*);
    virtual void setInsertionMethod(InsertionMethod);
    virtual void setEchoMode(EchoMode);
    virtual void setFontPercent(float);
    virtual void setMaxLineLength(int);
    virtual void setMaxLines(int);
    virtual void setHMargin(int);
    virtual void setSelection(int, int, int, int);
    virtual void resetFocusItem(bool);
    virtual void getCurrentFocusRect();
    virtual void hasNextPrevFocusItem(bool);
    virtual void changeContentSize(int, QPoint);
    virtual void setText(QString const&);
    virtual void setReadOnly(bool);
    virtual void setZEnabled(bool);
    virtual void setOverwriteMode(bool);
    virtual void drawLineText(QPainter*, int, int, int, int, int, QString const&, int, int);
    virtual void insert(QString const&, bool);
    virtual void newLine();
    virtual void killLine();
    virtual void pageUp(bool mark=FALSE);
    virtual void pageDown(bool mark=FALSE);
    virtual void cursorLeft(bool mark=FALSE, bool wrap = TRUE); //Moves the cursor one character to the left. If mark is TRUE, the text is marked. If wrap is TRUE, the cursor moves to the end of the previous line if it is placed at the beginning of the current line.
    virtual void cursorRight(bool mark=FALSE, bool wrap = TRUE);
    virtual void cursorUp(bool mark=FALSE);
    virtual void cursorDown(bool mark=FALSE);
    virtual void cursorMove(bool);
    virtual void backspace();
    virtual void del();
    virtual void home(bool mark=FALSE);
    virtual void end(bool mark=FALSE); //Moves the text cursor to the right end of the line. If mark is TRUE text is marked towards the last position. If it is FALSE and the cursor is moved, all marked text is unmarked.

    ZMultiLineEdit(QWidget *parent,bool EZXStyle,int lines = 1,const char *name=0 );
    ZMultiLineEdit(QWidget *parent,const char *name=0 );

	void addRedoCmd(ZMultiLineEditCommand*);
	void addReplacedStr(QString const&, int);
	void addUndoCmd(ZMultiLineEditCommand*);
	void afterMark(int, int) const;
	void alignment() const;
	void append(QString const&);
	void autoAlignment(TsLayout_*, TsLayoutInfo&);
	void autoExpandInNestMode() const;
	void autoSendScrollRequest(int, QPoint const&);
	void autoUpdate() const;
	void beforeMark(int, int) const;
	void blinkTimerTimeout();
	void bufferUpdate();
	void bufferUpdate(int, int);
	void calCursorPos(QPoint, int);
	void changeSizeHint(QWidget*, QSize, QPoint, int);
	void changeToLineType(int);
	void charClass(QChar);
	void clear();
	void clearUndoList();
	bool clicked();
	void clipboardChanged();
	void composeWidth(long&);
	void contentChanged();
	void contentsResizing(ZMultiLineEdit*, int, int);
	void copy() const;
	void copyAvailable(bool);
	void copyText() const;
	void cursorChanged(int, int);
  QPoint cursorPoint();
	void cursorPointViewed();
	void cursorPosBeforeInsert(int, int, int, int*, int*);
	void cursorPosition(int*, int*) const;
  void cursorRight(bool mark=FALSE, bool wrap = TRUE , bool);
	void cursorToLayoutIndex(int);
  void cursorUp(bool mark=FALSE, bool);
  void cursorWordBackward(bool);  //Moves the cursor one word to the left. If mark is TRUE, the text is marked.
	void cursorWordForward(bool);
	void cut();
	void defaultTabStop();
	void delAux();
	void deleteNextChar(int, int, int);
	void deleteText();
	void deleteWord();
	void deselect();
	void dndTimeout();
	void doControlKeyPress(QKeyEvent*);
	void doModalStatusKeyPress(QKeyEvent*);
	void doReadOnlyKeyPress(QKeyEvent*);
	void doSelectKeyPress();
	void drawMultiArea(QPainter*, QRect const&, QRect const&, ZSkinBase*);
	void drawOtherArea(QPainter*, QRect const&, QRect const&, ZSkinBase*);
	void drawTableFrame(QPainter*, QRect&);
	void drawUnderLine(QPainter*, int, int, int);
  EchoMode echoMode() const; //Returns the currently set echo mode.
  bool edited() const;    //Returns the edited flag of the line edit. If this returns FALSE, the contents has not been changed since the construction of the QMultiLineEdit (or the last call to setEdited( FALSE ), if any). If it returns TRUE, the contents have been edited, or setEdited( TRUE ) has been called.
	void emitTextChanged();
	bool event(QEvent*);
	void extendSelectionWord(int&, int&);
	void fastDelTimerTimeout();
	void filterString(QString&, QString const&);
	void firstNoVisibleLines(int, QRect const&, bool);
	void focusInEvent(QFocusEvent*);
	bool focusNextPrevChild(bool);
	void focusOutEvent(QFocusEvent*);
	void focusOutRange() const;
	void getContentsWidth();
  void getCorsorPosition(int&, int&, int); //Returns the current line and character position within that line, in the variables pointed to by line and col respectively.
	void getCursorOffset(int, int);
  void getCursorPosition(int*, int*) const;//Returns the current line and character position within that line, in the variables pointed to by line and col respectively.
	void getCursorState();
	void getEditArea();
	void getFilter() const;
	void getFormItemBottomArea();
	void getFormItemLeftArea();
	void getFormItemRightArea();
	void getFormItemTopArea();
	int getFrameWidth(int&, int&, int&, int&);
	int getHeight() const;
	int getIndent();
	void getInputField();
	QString getLineContent(int);
	int getLineCount();
	int getLineHeight() const;
	void getLinePixSuffixName(ZSkinBase::SelectionState, QString&);
	void getMDBottomArea();
	void getMDFrameWidth(int&, int&, int&, int&);
	void getMDLeftArea();
	void getMDRightArea();
	void getMDTopArea();
	void getMarkedRegion(int*, int*, int*, int*) const;
	void getOffset(int);
	void getParaAlignment();
	QPixmap* getPixmap(ZSkinBase::SelectionState);
	QString getRowString(int);
	void getSkinFont(QFont&, QColor&, TextType) const;
	void getTitleSize() const;
	void getTruncateCount();
	void getUnderline();
	void getWidth() const;
	void glyphRegion(TsGlyphInfo const&, int, int, int, int);
  int hMargin() const;  //Returns the horizontal margin current set. The default is 3.
	void handleEzxInsertString(QString const&, int);
	void handleNormalInsertString(QString const&, int, int);
  bool hasMarkedText() const; //Returns TRUE if there is marked text.
	void heightViewed() const;
	void inMark(int, int) const;
	void init(QWidget*, bool, int, char const*);
	void insert(QString const&);
	void insertAtAux(QString const&, int, int, bool);
	void insertAtSpecialEzxStyle(QString const&, int);
	void insertChar(QChar);
	void insertString_if(QPoint, QString);
	void invalidateTsLayout(int, bool);
	void isEndOfParagraph(int) const;
	void isLTRBidiClass(TsBidiCharClass);
	void isRTLBidiClass(TsBidiCharClass);
	void isUndoEnabled() const;
	void isValidChar(QChar const&);
	void isZDisabled();
	void isZEnabled();
	void keyPressEvent(QKeyEvent*);
	void keyReleaseEvent(QKeyEvent*);
	void killLineAux();
	void layoutIndexToCursor(int);
	void leaveEvent(QEvent*);
	void length() const;
	void lineColor(ZSkinBase::SelectionState, QColor&);
	void lineHeight();
	void lineType(ZSkinBase::SelectionState);
	void linesChanged(int, QPoint);
	void linesChangedNoExp(int);
	void loadLinePixmap(ZSkinBase::SelectionState);
	void makeVisible(bool);
	void mapFromView(int, int);
	void mapToView(int, int);
	void markWord(int, int);
	void markedText() const;
	void maxLength() const;
	void maxLineLength() const;
	void maxLineWidth() const;
	void maxLines() const;
	QSize minimumSizeHint() const;
	void mouseDoubleClickEvent(QMouseEvent*);
	void mouseMoveEvent(QMouseEvent*);
	void mousePressEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);
	void nestScrollPanelMode() const;
	void newMark(int, int, bool);
	void offsetToPositionInternal(int, int*, int*) const;
	void paintCell(QPainter*, int, int, int, int);
	void paintCell_if(QPainter*, int, int, bool, int, bool, int, int, QString, QFontMetrics, QRect, QColorGroup);
	void paintEvent(QPaintEvent*);
	void partiallyInvisible(int);
	void paste();
	void pasteSubType(QCString const&);
	void phonenoText() const;
	void pickSpecial(QMimeSource*, bool, QPoint const&);
	void pixelPosToCursorPos(QPoint, int*, int*);
	void positionToOffsetInternal(int, int) const;
	void prepareTsLayout(int);
	void prepareTsMarkRegion(int, int, int, int, int, int, int, QString const&);
	void processCmd(ZMultiLineEditCommand*, bool);
	void rebreakAll();
	void rebreakParagraph(int, int);
	void redo();
	void redoAvailable(bool);
	void resizeEvent(QResizeEvent*);
	void returnPressed();
	void rightSmartPuncOccurred();
	void scrollTimerTimeout();
	void selectAll();
	void setAlignment(int);
	void setAutoExpandInNestMode(bool);
	void setAutoFixedHeight(bool);
	void setAutoUpdate(bool);
	void setBottomCell(int);
	void setCursorFlagDirection(CursorFlagDirection);
	void setCursorPixelPosition(QPoint, bool);
	void setDefaultTabStop(int);
	void setEdited(bool);   // if true, then cursor position is not changed when MultiLineEdit  focus out
                          // if false, then cursor position changed to begin or end (depend on InsertationMethod) of text when MultiLineEdit focus out
	void setFilter(QRegExp const&, bool);
	void setFont(QFont const&);
	void setIndent(int);
	void setMaxLength(int);
	void setMoveFocusOutRange(bool);
	void setNestScrollPanelMode(bool);
	void setNumRowsAndTruncate();
	void setPalette(QPalette const&);
	void setStateFont(bool);
	void setTitle(QString const&);
	void setTitlePosition(TitlePosition);
	void setTitlePositionAux(QString const&, int);
	void setTruncateInfo(int, QString const&);
	void setUnderline(bool);
	void setUndoDepth(int);
	void setUndoEnabled(bool);
	void setViewMarginsEx();
	void setWidth(int);
	void setWordComplete(bool);
	void setWordWrap(WordWrap);
	void setWrapColumnOrWidth(int);
	void setWrapPolicy(ZWrapPolicy);
	void show();
	void sigCursorUpDown(bool);
	QSize sizeHint() const;
	QSizePolicy sizePolicy() const;
	void smartPunctuation();
	void specialInputModeCursorModel(bool);
	void startAutoScroll();
	void stopAutoScroll();
	void stretchPixmap(QPixmap&, int, int, PIXMAP_STRETCH_POLICY_E);
	void stringShown(int) const;
  QString text() const;
	void textChanged();
	QString textLine(int) const;
	void textTrancated();
	void textWidth(int);
	void textWidthWithTabs(int);
	void timerEvent(QTimerEvent*);
	void title() const;
	void turnMark(bool);
	void undo();
	void undoAvailable(bool);
	void undoDepth() const;
	void updateCellWidth();
	void updateFontInfo(QFont*, ZFontInfo const&);
	void updateMask();
	void updateSkin(bool);
	void updateTextLayout();
	void validator() const;
	void wheelEvent(QWheelEvent*);
	void wordWrap() const;
	void wrapColumnOrWidth() const;
	void wrapLine(int, int);
	void wrapPolicy() const;
	void wtleWrapLine(int, int&, int&);
	void xPosToCursorPos(int, int);

};

#endif
