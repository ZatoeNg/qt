#ifndef SYNTAX_HIGHLIGHTER_H
#define SYNTAX_HIGHLIGHTER_H
#include <QSyntaxHighlighter>
#include <QTextDocument>
class MySyntaxHighlighter:public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit MySyntaxHighlighter(QTextDocument* parent = 0);
    //重写实现高亮
protected:
    void highlightBlock(const QString& text);

    void set_match_format(const QString &text, const QString &pattern, const QTextCharFormat &format);
};

#endif // SYNTAX_HIGHLIGHTER_H
