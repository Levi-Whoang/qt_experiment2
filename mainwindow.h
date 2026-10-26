
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QColor>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString currentFile;
    QColor editorBackgroundColor = Qt::white;

    // 文件操作
    void newFile();
    void openFile();
    void saveFile();
    void saveAsFile();
    bool saveToFile(const QString &fileName);
    bool maybeSave();
    void updateWindowTitle();

    // 查找与替换
    void findText();
    void replaceText();

    // 格式设置
    void chooseFont();
    void chooseFontColor();
    void chooseFontBackgroundColor();
    void chooseEditorBackgroundColor();
    void setWordWrap(bool enabled);

    // 其他功能
    void showAbout();
    void updateStatusBar();
    void setupConnections();
    void setupShortcuts();
};

#endif // MAINWINDOW_H
