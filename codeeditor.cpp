
#include "codeeditor.h"

#include <QPainter>
#include <QTextBlock>
#include <QTextCursor>
#include <QTextFormat>
#include <QColor>
#include <QFontMetrics>
#include <QScrollBar>

CodeEditor::CodeEditor(QWidget *parent)
    : QPlainTextEdit(parent),
    lineNumberArea(new LineNumberArea(this))
{
    connect(this, &QPlainTextEdit::blockCountChanged,
            this, &CodeEditor::updateLineNumberAreaWidth);

    connect(this, &QPlainTextEdit::updateRequest,
            this, &CodeEditor::updateLineNumberArea);

    connect(this, &QPlainTextEdit::cursorPositionChanged,
            this, &CodeEditor::highlightCurrentLine);

    updateLineNumberAreaWidth();
    highlightCurrentLine();
}

int CodeEditor::lineNumberAreaWidth() const
{
    int digits = 1;
    int maxNumber = qMax(1, blockCount());

    while (maxNumber >= 10) {
        maxNumber /= 10;
        ++digits;
    }

    return 10 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;
}

void CodeEditor::updateLineNumberAreaWidth()
{
    setViewportMargins(
        lineNumbersVisible ? lineNumberAreaWidth() : 0,
        0, 0, 0
        );
}

void CodeEditor::updateLineNumberArea(const QRect &rect)
{
    if (!lineNumbersVisible) {
        return;
    }

    if (rect.contains(viewport()->rect())) {
        lineNumberArea->update();
    } else {
        lineNumberArea->scroll(0, rect.y());
    }

    if (rect.height() > 0) {
        lineNumberArea->update(
            0, rect.y(),
            lineNumberArea->width(), rect.height()
            );
    }

    if (rect.width() > 0) {
        updateLineNumberAreaWidth();
    }
}

void CodeEditor::resizeEvent(QResizeEvent *event)
{
    QPlainTextEdit::resizeEvent(event);

    QRect rect = contentsRect();
    lineNumberArea->setGeometry(
        QRect(rect.left(),
              rect.top(),
              lineNumberAreaWidth(),
              rect.height())
        );
}

void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    if (!lineNumbersVisible) {
        return;
    }

    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), QColor(240, 240, 240));

    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();

    int top = qRound(
        blockBoundingGeometry(block).translated(contentOffset()).top()
        );

    int bottom = top + qRound(blockBoundingRect(block).height());

    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            painter.setPen(Qt::darkGray);

            painter.drawText(
                0,
                top,
                lineNumberArea->width() - 4,
                fontMetrics().height(),
                Qt::AlignRight,
                QString::number(blockNumber + 1)
                );
        }

        block = block.next();
        top = bottom;

        if (block.isValid()) {
            bottom = top + qRound(blockBoundingRect(block).height());
        }

        ++blockNumber;
    }
}

void CodeEditor::setLineNumberAreaVisible(bool visible)
{
    lineNumbersVisible = visible;
    lineNumberArea->setVisible(visible);
    updateLineNumberAreaWidth();
    updateLineNumberArea(QRect(0, 0, viewport()->width(), viewport()->height()));
}

void CodeEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> selections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        selection.format.setBackground(QColor(232, 242, 254));
        selection.format.setProperty(
            QTextFormat::FullWidthSelection, true
            );

        selection.cursor = textCursor();
        selection.cursor.clearSelection();

        selections.append(selection);
    }

    setExtraSelections(selections);
}

LineNumberArea::LineNumberArea(CodeEditor *editor)
    : QWidget(editor),
    codeEditor(editor)
{
}

QSize LineNumberArea::sizeHint() const
{
    return QSize(codeEditor->lineNumberAreaWidth(), 0);
}

void LineNumberArea::paintEvent(QPaintEvent *event)
{
    codeEditor->lineNumberAreaPaintEvent(event);
}
