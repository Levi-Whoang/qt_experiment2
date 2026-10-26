
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "codeeditor.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QTextDocument>
#include <QFontDialog>
#include <QColorDialog>
#include <QInputDialog>
#include <QFont>
#include <QStatusBar>
#include <QToolBar>
#include <QAction>
#include <QTextCursor>
#include <QTextCharFormat>
#include <QTextDocument>
#include <QFileInfo>
#include <QTextBlock>
#include <QKeySequence>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 默认显示行号、工具栏和状态栏
    ui->actionLineNumber->setChecked(true);
    ui->actionToolBar->setChecked(true);
    ui->actionStatusBar->setChecked(true);

    ui->plainTextEdit->setLineNumberAreaVisible(true);
    ui->plainTextEdit->setWordWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);

    setupConnections();
    setupShortcuts();
    updateWindowTitle();
    updateStatusBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupConnections()
{
    // 文件菜单
    connect(ui->actionNew, &QAction::triggered,
            this, &MainWindow::newFile);
    connect(ui->actionOpen, &QAction::triggered,
            this, &MainWindow::openFile);
    connect(ui->actionSave, &QAction::triggered,
            this, &MainWindow::saveFile);
    connect(ui->actionSaveAs, &QAction::triggered,
            this, &MainWindow::saveAsFile);
    connect(ui->actionQuit, &QAction::triggered,
            this, &QWidget::close);

    // 编辑菜单
    connect(ui->actionUndo, &QAction::triggered,
            ui->plainTextEdit, &QPlainTextEdit::undo);
    connect(ui->actionRedo, &QAction::triggered,
            ui->plainTextEdit, &QPlainTextEdit::redo);
    connect(ui->actionCut, &QAction::triggered,
            ui->plainTextEdit, &QPlainTextEdit::cut);
    connect(ui->actionCopy, &QAction::triggered,
            ui->plainTextEdit, &QPlainTextEdit::copy);
    connect(ui->actionPaste, &QAction::triggered,
            ui->plainTextEdit, &QPlainTextEdit::paste);
    connect(ui->actionSelectAll, &QAction::triggered,
            ui->plainTextEdit, &QPlainTextEdit::selectAll);

    connect(ui->actionFind, &QAction::triggered,
            this, &MainWindow::findText);
    connect(ui->actionReplace, &QAction::triggered,
            this, &MainWindow::replaceText);

    // 格式菜单
    connect(ui->actionWordWrap, &QAction::toggled,
            this, &MainWindow::setWordWrap);

    connect(ui->actionLineNumber, &QAction::toggled,
            ui->plainTextEdit, &CodeEditor::setLineNumberAreaVisible);

    connect(ui->actionFont, &QAction::triggered,
            this, &MainWindow::chooseFont);
    connect(ui->actionFontColor, &QAction::triggered,
            this, &MainWindow::chooseFontColor);
    connect(ui->actionFontBackgroundColor, &QAction::triggered,
            this, &MainWindow::chooseFontBackgroundColor);
    connect(ui->actionEditorBackgroundColor, &QAction::triggered,
            this, &MainWindow::chooseEditorBackgroundColor);

    // 查看菜单
    connect(ui->actionToolBar, &QAction::toggled,
            ui->toolBar, &QToolBar::setVisible);

    connect(ui->actionStatusBar, &QAction::toggled,
            ui->statusbar, &QStatusBar::setVisible);

    // 帮助菜单
    connect(ui->actionAbout, &QAction::triggered,
            this, &MainWindow::showAbout);

    // 文本变化时更新标题和状态栏
    connect(ui->plainTextEdit, &QPlainTextEdit::textChanged,
            this, &MainWindow::updateWindowTitle);

    connect(ui->plainTextEdit, &QPlainTextEdit::cursorPositionChanged,
            this, &MainWindow::updateStatusBar);
}

void MainWindow::setupShortcuts()
{
    ui->actionNew->setShortcut(QKeySequence::New);
    ui->actionOpen->setShortcut(QKeySequence::Open);
    ui->actionSave->setShortcut(QKeySequence::Save);
    ui->actionSaveAs->setShortcut(QKeySequence("Ctrl+Shift+S"));
    ui->actionQuit->setShortcut(QKeySequence::Quit);

    ui->actionUndo->setShortcut(QKeySequence::Undo);
    ui->actionRedo->setShortcut(QKeySequence::Redo);
    ui->actionCut->setShortcut(QKeySequence::Cut);
    ui->actionCopy->setShortcut(QKeySequence::Copy);
    ui->actionPaste->setShortcut(QKeySequence::Paste);
    ui->actionSelectAll->setShortcut(QKeySequence::SelectAll);
    ui->actionFind->setShortcut(QKeySequence::Find);
    ui->actionReplace->setShortcut(QKeySequence("Ctrl+H"));
}

void MainWindow::newFile()
{
    if (!maybeSave()) {
        return;
    }

    ui->plainTextEdit->clear();
    currentFile.clear();

    ui->plainTextEdit->document()->setModified(false);
    updateWindowTitle();
}

void MainWindow::openFile()
{
    if (!maybeSave()) {
        return;
    }

    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("打开文件"),
        QString(),
        tr("文本文件 (*.txt);;所有文件 (*)")
        );

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(
            this, tr("打开失败"),
            tr("无法打开文件：%1").arg(file.errorString())
            );
        return;
    }

    QTextStream in(&file);
    ui->plainTextEdit->setPlainText(in.readAll());

    currentFile = fileName;
    ui->plainTextEdit->document()->setModified(false);

    updateWindowTitle();
}

void MainWindow::saveFile()
{
    if (currentFile.isEmpty()) {
        saveAsFile();
        return;
    }

    saveToFile(currentFile);
}

void MainWindow::saveAsFile()
{
    QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("另存为"),
        currentFile.isEmpty() ? QString() : currentFile,
        tr("文本文件 (*.txt);;所有文件 (*)")
        );

    if (fileName.isEmpty()) {
        return;
    }

    if (saveToFile(fileName)) {
        currentFile = fileName;
        updateWindowTitle();
    }
}

bool MainWindow::saveToFile(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(
            this, tr("保存失败"),
            tr("无法保存文件：%1").arg(file.errorString())
            );
        return false;
    }

    QTextStream out(&file);
    out << ui->plainTextEdit->toPlainText();

    file.close();

    ui->plainTextEdit->document()->setModified(false);
    currentFile = fileName;

    updateWindowTitle();
    return true;
}

bool MainWindow::maybeSave()
{
    if (!ui->plainTextEdit->document()->isModified()) {
        return true;
    }

    QMessageBox::StandardButton result = QMessageBox::warning(
        this,
        tr("文档尚未保存"),
        tr("当前文档已修改，是否保存？"),
        QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel
        );

    if (result == QMessageBox::Save) {
        saveFile();
        return !ui->plainTextEdit->document()->isModified();
    }

    if (result == QMessageBox::Discard) {
        return true;
    }

    return false;
}

void MainWindow::updateWindowTitle()
{
    QString title = currentFile.isEmpty()
    ? tr("未命名")
    : QFileInfo(currentFile).fileName();

    if (ui->plainTextEdit->document()->isModified()) {
        title += "*";
    }

    setWindowTitle(title + tr(" - 简易文本编辑器"));
}

void MainWindow::findText()
{
    bool ok = false;

    QString text = QInputDialog::getText(
        this, tr("查找"),
        tr("请输入要查找的内容："),
        QLineEdit::Normal, QString(), &ok
        );

    if (!ok || text.isEmpty()) {
        return;
    }

    bool found = ui->plainTextEdit->find(text);

    if (!found) {
        QTextCursor cursor = ui->plainTextEdit->textCursor();
        cursor.movePosition(QTextCursor::Start);
        ui->plainTextEdit->setTextCursor(cursor);

        found = ui->plainTextEdit->find(text);
    }

    if (!found) {
        QMessageBox::information(this, tr("查找"), tr("没有找到匹配内容。"));
    }
}

void MainWindow::replaceText()
{
    bool ok = false;

    QString target = QInputDialog::getText(
        this, tr("替换"),
        tr("请输入要查找的内容："),
        QLineEdit::Normal, QString(), &ok
        );

    if (!ok || target.isEmpty()) {
        return;
    }

    QString replacement = QInputDialog::getText(
        this, tr("替换"),
        tr("请输入替换后的内容："),
        QLineEdit::Normal, QString(), &ok
        );

    if (!ok) {
        return;
    }

    QTextCursor cursor = ui->plainTextEdit->textCursor();

    if (cursor.hasSelection() && cursor.selectedText() == target) {
        cursor.insertText(replacement);
    } else if (!ui->plainTextEdit->find(target)) {
        cursor.movePosition(QTextCursor::Start);

        ui->plainTextEdit->setTextCursor(cursor);

        if (!ui->plainTextEdit->find(target)) {
            QMessageBox::information(
                this, tr("替换"), tr("没有找到匹配内容。")
                );
            return;
        }

        cursor = ui->plainTextEdit->textCursor();
        cursor.insertText(replacement);
    } else {
        cursor = ui->plainTextEdit->textCursor();
        cursor.insertText(replacement);
    }
}

void MainWindow::chooseFont()
{
    bool ok = false;

    QFont font = QFontDialog::getFont(
        &ok, ui->plainTextEdit->font(), this, tr("选择字体")
        );

    if (ok) {
        ui->plainTextEdit->setFont(font);
    }
}

void MainWindow::chooseFontColor()
{
    QColor color = QColorDialog::getColor(
        Qt::black, this, tr("选择字体颜色")
        );

    if (!color.isValid()) {
        return;
    }

    QTextCursor cursor = ui->plainTextEdit->textCursor();
    QTextCharFormat format;
    format.setForeground(color);

    if (!cursor.hasSelection()) {
        cursor.select(QTextCursor::WordUnderCursor);
    }

    if (cursor.hasSelection()) {
        cursor.mergeCharFormat(format);
    } else {
        ui->plainTextEdit->mergeCurrentCharFormat(format);
    }
}

void MainWindow::chooseFontBackgroundColor()
{
    QColor color = QColorDialog::getColor(
        Qt::yellow, this, tr("选择字体背景色")
        );

    if (!color.isValid()) {
        return;
    }

    QTextCursor cursor = ui->plainTextEdit->textCursor();
    QTextCharFormat format;
    format.setBackground(color);

    if (!cursor.hasSelection()) {
        cursor.select(QTextCursor::WordUnderCursor);
    }

    if (cursor.hasSelection()) {
        cursor.mergeCharFormat(format);
    } else {
        ui->plainTextEdit->mergeCurrentCharFormat(format);
    }
}

void MainWindow::chooseEditorBackgroundColor()
{
    QColor color = QColorDialog::getColor(
        editorBackgroundColor, this, tr("选择编辑器背景色")
        );

    if (!color.isValid()) {
        return;
    }

    editorBackgroundColor = color;

    ui->plainTextEdit->setStyleSheet(
        QString("QPlainTextEdit { background-color: %1; }")
            .arg(color.name())
        );
}

void MainWindow::setWordWrap(bool enabled)
{
    ui->plainTextEdit->setLineWrapMode(
        enabled ? QPlainTextEdit::WidgetWidth
                : QPlainTextEdit::NoWrap
        );
}

void MainWindow::showAbout()
{
    QMessageBox::about(
        this,
        tr("关于"),
        tr("简易文本编辑器\n基于 Qt Widgets 开发。")
        );
}

void MainWindow::updateStatusBar()
{
    QTextCursor cursor = ui->plainTextEdit->textCursor();

    int line = cursor.blockNumber() + 1;
    int column = cursor.positionInBlock() + 1;

    ui->statusbar->showMessage(
        tr("第 %1 行，第 %2 列").arg(line).arg(column)
        );
}
