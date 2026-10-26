
#ifndef LINENUMBERAREA_H
#define LINENUMBERAREA_H

#include <QWidget>

class QPlainTextEdit;

class LineNumberArea : public QWidget
{
public:
    explicit LineNumberArea(QPlainTextEdit *editor);

    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPlainTextEdit *editor;
};

#endif // LINENUMBERAREA_H
