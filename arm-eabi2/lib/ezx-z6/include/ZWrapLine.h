#ifndef _ZWRAPLINE_H_
#define _ZWRAPLINE_H_ 1

class TsLayout_;
class TsLayoutInfo;

/* Size 564 = 141*4 */

class ZWrapLine
{
	unsigned int data[141];
public:
	ZWrapLine(QString&);
	~ZWrapLine();

	enum WordWrap {
	};
	enum WrapPolicy {
	};

	void getNumLines();
	void setWordWrap(WordWrap);
	void setAlignment(Qt::AlignmentFlags);
	void setStrSource(QString&);
	void autoAlignment(TsLayout_*, TsLayoutInfo&);
	void setWrapPolicy(WrapPolicy);
	void clearChartable();
	void getLineContent(int, QString&, bool&);
	void setContentsWidth(int);
	void setWrapColumnOrWidth(int);
	void clear();
	void wrapLine(QFont const&);
	void wrapPolicy() const;
	void wrapColumnOrWidth() const;
	void draw(QPainter*, int, int, QRect const&) const;
	void width() const;
	void height() const;
	void wordWrap() const;
	void alignment() const;
};

#endif
