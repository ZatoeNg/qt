#include "syntax_highlighter.h"
#include <QFont>
#include <QRegularExpression>

MySyntaxHighlighter::MySyntaxHighlighter(QTextDocument* parent):QSyntaxHighlighter (parent)
{

}

void MySyntaxHighlighter::highlightBlock(const QString &text)
{
    //关键字：蓝色加粗
    QTextCharFormat key_format;
    key_format.setFont(QFont("微软雅黑"));
    key_format.setFontWeight(QFont::Bold);
    key_format.setForeground(Qt::green);

    // 字符串：红色
    QTextCharFormat string_format;
    string_format.setForeground(Qt::red);

    // 注释：灰色斜体
    QTextCharFormat comment_format;
    comment_format.setForeground(Qt::darkGray);
    comment_format.setFontItalic(true);

    // 数字：紫色
    QTextCharFormat number_format;
    number_format.setForeground(Qt::darkMagenta);

    //创建正则表达式
    QString patten = "(?<!\\w)(alignas|alignof|and|and_eq|asm|auto|bitand|bitor|bool|break|case|catch"
                     "|char|char8_t|char16_t|char32_t|class|compl|concept|const|consteval|constexpr"
                     "|const_cast|continue|co_await|co_return|co_yield|decltype|default|delete|do|double"
                     "|dynamic_cast|else|enum|explicit|export|extern|false|float|for|friend|goto|if|inline"
                     "|int|long|mutable|namespace|new|noexcept|not|not_eq|nullptr|operator|or|or_eq|private"
                     "|protected|public|register|reinterpret_cast|requires|return|short|signed|sizeof|static"
                     "|static_assert|static_cast|struct|switch|template|this|thread_local|throw|true|try"
                     "|typedef|typeid|typename|union|unsigned|using|virtual|void|volatile|wchar_t|while"
                     "|xor|xor_eq)(?!\\w)";

    // 高亮关键字
    set_match_format(text, patten, key_format);
    // 高亮字符串 "..."
    set_match_format(text, R"(".*?")", string_format);
    // 高亮单行注释 //...
    set_match_format(text, R"(//.*)", comment_format);
    // 高亮数字
    set_match_format(text, R"(\b\d+\.?\d*\b)", number_format);
}

void MySyntaxHighlighter::set_match_format(const QString &text, const QString &pattern, const QTextCharFormat &format)
{

    QRegularExpression regx(pattern);
    // 全局匹配
    QRegularExpressionMatchIterator it = regx.globalMatch(text);

    while (it.hasNext()) {
        // 拿到下一个匹配结果
        QRegularExpressionMatch match = it.next();
        //匹配的位置
        int index = match.capturedStart();
        //匹配的长度
        int matchLen = match.capturedLength();
        setFormat(index, matchLen, format);
    }
}



