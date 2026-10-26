
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>
#include <QString>
#include <QTextCursor>
#include <QTextCharFormat>
#include <QResizeEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class LineNumberArea;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::MainWindow *ui;

    QString currentFile;
    LineNumberArea *lineNumberArea = nullptr;
    QColor editorBackgroundColor = Qt::white;

    // 文件操作
    void newFile();
    void openFile();
    void saveFile();
    void saveAsFile();
    bool saveToFile(const QString &fileName);
    bool maybeSave();
    void updateWindowTitle();

    // 编辑操作
    void findText();
    void replaceText();
    void replaceAllText();

    // 格式设置
    void chooseFont();
    void chooseFontColor();
    void chooseFontBackgroundColor();
    void chooseEditorBackgroundColor();
    void setWordWrap(bool enabled);

    // 行号
    void updateLineNumberAreaWidth();
    void updateLineNumberAreaPaint(const QRect &rect);
    void paintLineNumberArea(QPaintEvent *event);

    // 其他
    void showAbout();
    void updateStatusBar();
    void setupIcons();
};

#endif // MAINWINDOW_H
