/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "codeeditor.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionFontColor;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionWordWrap;
    QAction *actionQuit;
    QAction *actionFind;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionReplace;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionToolBar;
    QAction *actionPaste;
    QAction *actionStatusBar;
    QAction *actionSelectAll;
    QAction *actionLineNumber;
    QAction *actionFont;
    QAction *actionAbout;
    QAction *actionFontBackgroundColor;
    QAction *actionEditorBackgroundColor;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    CodeEditor *plainTextEdit;
    QMenuBar *menubar;
    QMenu *menu_F;
    QMenu *menu_E;
    QMenu *menu_O;
    QMenu *menu_V;
    QMenu *menu_H;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        QIcon icon;
        icon.addFile(QString::fromUtf8("image/\345\261\217\345\271\225\346\210\252\345\233\276 2026-10-26 230853.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionNew->setIcon(icon);
        actionNew->setMenuRole(QAction::MenuRole::NoRole);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("image/\345\261\217\345\271\225\346\210\252\345\233\276 2026-10-26 231017.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionOpen->setIcon(icon1);
        actionOpen->setMenuRole(QAction::MenuRole::NoRole);
        actionFontColor = new QAction(MainWindow);
        actionFontColor->setObjectName("actionFontColor");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("image/\345\261\217\345\271\225\346\210\252\345\233\276 2026-10-26 231112.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionFontColor->setIcon(icon2);
        actionFontColor->setMenuRole(QAction::MenuRole::NoRole);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("image/\345\261\217\345\271\225\346\210\252\345\233\276 2026-10-26 231024.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSave->setIcon(icon3);
        actionSave->setMenuRole(QAction::MenuRole::NoRole);
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName("actionSaveAs");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("image/\345\261\217\345\271\225\346\210\252\345\233\276 2026-10-26 231030.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSaveAs->setIcon(icon4);
        actionSaveAs->setMenuRole(QAction::MenuRole::NoRole);
        actionWordWrap = new QAction(MainWindow);
        actionWordWrap->setObjectName("actionWordWrap");
        actionWordWrap->setCheckable(true);
        actionWordWrap->setChecked(true);
        actionWordWrap->setMenuRole(QAction::MenuRole::NoRole);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName("actionQuit");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("image/\345\261\217\345\271\225\346\210\252\345\233\276 2026-10-26 231938.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionQuit->setIcon(icon5);
        actionQuit->setMenuRole(QAction::MenuRole::NoRole);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName("actionFind");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("image/\345\261\217\345\271\225\346\210\252\345\233\276 2026-10-26 231058.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionFind->setIcon(icon6);
        actionFind->setMenuRole(QAction::MenuRole::NoRole);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("image/\345\261\217\345\271\225\346\210\252\345\233\276 2026-10-26 231035.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionUndo->setIcon(icon7);
        actionUndo->setMenuRole(QAction::MenuRole::NoRole);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName("actionRedo");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("image/\345\261\217\345\271\225\346\210\252\345\233\276 2026-10-26 231039.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionRedo->setIcon(icon8);
        actionRedo->setMenuRole(QAction::MenuRole::NoRole);
        actionReplace = new QAction(MainWindow);
        actionReplace->setObjectName("actionReplace");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("image/\345\261\217\345\271\225\346\210\252\345\233\276 2026-10-26 231102.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionReplace->setIcon(icon9);
        actionReplace->setMenuRole(QAction::MenuRole::NoRole);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName("actionCut");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("image/\345\261\217\345\271\225\346\210\252\345\233\276 2026-10-26 231044.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionCut->setIcon(icon10);
        actionCut->setMenuRole(QAction::MenuRole::NoRole);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName("actionCopy");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("image/\345\261\217\345\271\225\346\210\252\345\233\276 2026-10-26 231049.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionCopy->setIcon(icon11);
        actionCopy->setMenuRole(QAction::MenuRole::NoRole);
        actionToolBar = new QAction(MainWindow);
        actionToolBar->setObjectName("actionToolBar");
        actionToolBar->setCheckable(true);
        actionToolBar->setChecked(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8("image/\345\261\217\345\271\225\346\210\252\345\233\276 2026-10-26 231518.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionToolBar->setIcon(icon12);
        actionToolBar->setMenuRole(QAction::MenuRole::NoRole);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName("actionPaste");
        QIcon icon13;
        icon13.addFile(QString::fromUtf8("image/\345\261\217\345\271\225\346\210\252\345\233\276 2026-10-26 231053.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionPaste->setIcon(icon13);
        actionPaste->setMenuRole(QAction::MenuRole::NoRole);
        actionStatusBar = new QAction(MainWindow);
        actionStatusBar->setObjectName("actionStatusBar");
        actionStatusBar->setCheckable(true);
        actionStatusBar->setChecked(true);
        actionStatusBar->setIcon(icon12);
        actionStatusBar->setMenuRole(QAction::MenuRole::NoRole);
        actionSelectAll = new QAction(MainWindow);
        actionSelectAll->setObjectName("actionSelectAll");
        QIcon icon14;
        icon14.addFile(QString::fromUtf8("image/\345\261\217\345\271\225\346\210\252\345\233\276 2026-10-26 231707.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSelectAll->setIcon(icon14);
        actionSelectAll->setMenuRole(QAction::MenuRole::NoRole);
        actionLineNumber = new QAction(MainWindow);
        actionLineNumber->setObjectName("actionLineNumber");
        actionLineNumber->setCheckable(true);
        actionLineNumber->setChecked(true);
        actionLineNumber->setMenuRole(QAction::MenuRole::NoRole);
        actionFont = new QAction(MainWindow);
        actionFont->setObjectName("actionFont");
        QIcon icon15;
        icon15.addFile(QString::fromUtf8("image/font-size-2.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionFont->setIcon(icon15);
        actionFont->setMenuRole(QAction::MenuRole::NoRole);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        QIcon icon16;
        icon16.addFile(QString::fromUtf8("image/\345\261\217\345\271\225\346\210\252\345\233\276 2026-10-26 231115.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionAbout->setIcon(icon16);
        actionAbout->setMenuRole(QAction::MenuRole::NoRole);
        actionFontBackgroundColor = new QAction(MainWindow);
        actionFontBackgroundColor->setObjectName("actionFontBackgroundColor");
        actionFontBackgroundColor->setIcon(icon2);
        actionFontBackgroundColor->setMenuRole(QAction::MenuRole::NoRole);
        actionEditorBackgroundColor = new QAction(MainWindow);
        actionEditorBackgroundColor->setObjectName("actionEditorBackgroundColor");
        actionEditorBackgroundColor->setIcon(icon2);
        actionEditorBackgroundColor->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        plainTextEdit = new CodeEditor(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");

        verticalLayout->addWidget(plainTextEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menu_F = new QMenu(menubar);
        menu_F->setObjectName("menu_F");
        menu_E = new QMenu(menubar);
        menu_E->setObjectName("menu_E");
        menu_O = new QMenu(menubar);
        menu_O->setObjectName("menu_O");
        menu_V = new QMenu(menubar);
        menu_V->setObjectName("menu_V");
        menu_H = new QMenu(menubar);
        menu_H->setObjectName("menu_H");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menu_F->menuAction());
        menubar->addAction(menu_E->menuAction());
        menubar->addAction(menu_O->menuAction());
        menubar->addAction(menu_V->menuAction());
        menubar->addAction(menu_H->menuAction());
        menu_F->addAction(actionNew);
        menu_F->addAction(actionOpen);
        menu_F->addAction(actionSave);
        menu_F->addAction(actionSaveAs);
        menu_F->addAction(actionQuit);
        menu_E->addAction(actionUndo);
        menu_E->addAction(actionRedo);
        menu_E->addAction(actionCut);
        menu_E->addAction(actionCopy);
        menu_E->addAction(actionPaste);
        menu_E->addSeparator();
        menu_E->addAction(actionFind);
        menu_E->addAction(actionReplace);
        menu_E->addSeparator();
        menu_E->addAction(actionSelectAll);
        menu_O->addAction(actionWordWrap);
        menu_O->addAction(actionLineNumber);
        menu_O->addAction(actionFont);
        menu_O->addAction(actionFontColor);
        menu_O->addSeparator();
        menu_O->addAction(actionFontBackgroundColor);
        menu_O->addAction(actionEditorBackgroundColor);
        menu_V->addAction(actionToolBar);
        menu_V->addAction(actionStatusBar);
        menu_H->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272&N", nullptr));
#if QT_CONFIG(tooltip)
        actionNew->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200&O", nullptr));
#if QT_CONFIG(tooltip)
        actionOpen->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFontColor->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\351\242\234\350\211\262&C", nullptr));
#if QT_CONFIG(tooltip)
        actionFontColor->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\346\226\207\345\255\227\351\242\234\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230&S", nullptr));
#if QT_CONFIG(tooltip)
        actionSave->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSaveAs->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272&A", nullptr));
#if QT_CONFIG(tooltip)
        actionSaveAs->setToolTip(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272\345\205\266\344\273\226\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSaveAs->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionWordWrap->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\215\242\350\241\214&W", nullptr));
#if QT_CONFIG(tooltip)
        actionWordWrap->setToolTip(QCoreApplication::translate("MainWindow", "\345\274\200\345\220\257\346\210\226\345\205\263\351\227\255\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
#endif // QT_CONFIG(tooltip)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272&X", nullptr));
#if QT_CONFIG(tooltip)
        actionQuit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFind->setText(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276&F", nullptr));
#if QT_CONFIG(tooltip)
        actionFind->setToolTip(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276\346\226\207\346\234\254", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionFind->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUndo->setText(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200&Z", nullptr));
#if QT_CONFIG(tooltip)
        actionUndo->setToolTip(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200\344\270\212\344\270\200\346\255\245\346\223\215\344\275\234", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRedo->setText(QCoreApplication::translate("MainWindow", "\346\201\242\345\244\215&Y", nullptr));
#if QT_CONFIG(tooltip)
        actionRedo->setToolTip(QCoreApplication::translate("MainWindow", "\351\207\215\345\201\232\350\242\253\346\222\244\351\224\200\347\232\204\346\223\215\344\275\234", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionRedo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actionReplace->setText(QCoreApplication::translate("MainWindow", "\346\233\277\346\215\242&R", nullptr));
#if QT_CONFIG(tooltip)
        actionReplace->setToolTip(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276\345\271\266\346\233\277\346\215\242\344\270\200\345\244\204", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionReplace->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207&T", nullptr));
#if QT_CONFIG(tooltip)
        actionCut->setToolTip(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207\351\200\211\344\270\255\347\232\204\345\206\205\345\256\271", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266&C", nullptr));
#if QT_CONFIG(tooltip)
        actionCopy->setToolTip(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266\351\200\211\344\270\255\347\232\204\345\206\205\345\256\271", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionToolBar->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\267\245\345\205\267\346\240\217&T", nullptr));
#if QT_CONFIG(tooltip)
        actionToolBar->setToolTip(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\346\210\226\351\232\220\350\227\217\345\267\245\345\205\267\346\240\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actionPaste->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264&V", nullptr));
#if QT_CONFIG(tooltip)
        actionPaste->setToolTip(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264\345\211\252\350\264\264\346\235\277\345\206\205\345\256\271", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStatusBar->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\347\212\266\346\200\201\346\240\217&S", nullptr));
#if QT_CONFIG(tooltip)
        actionStatusBar->setToolTip(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\346\210\226\351\232\220\350\227\217\347\212\266\346\200\201\346\240\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSelectAll->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\200\211&A", nullptr));
#if QT_CONFIG(tooltip)
        actionSelectAll->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\211\344\270\255\345\205\250\351\203\250\346\226\207\346\234\254", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSelectAll->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLineNumber->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\350\241\214\345\217\267&L", nullptr));
#if QT_CONFIG(tooltip)
        actionLineNumber->setToolTip(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\346\210\226\351\232\220\350\227\217\350\241\214\345\217\267\346\240\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actionFont->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223&F", nullptr));
#if QT_CONFIG(tooltip)
        actionFont->setToolTip(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\345\255\227\344\275\223\343\200\201\345\255\227\345\217\267", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216&A", nullptr));
#if QT_CONFIG(tooltip)
        actionAbout->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216\346\234\254\347\250\213\345\272\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actionFontBackgroundColor->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\350\203\214\346\231\257\350\211\262&B", nullptr));
        actionEditorBackgroundColor->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\345\231\250\350\203\214\346\231\257\350\211\262&E", nullptr));
        menu_F->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\357\274\210&F\357\274\211", nullptr));
        menu_E->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\357\274\210&E\357\274\211", nullptr));
        menu_O->setTitle(QCoreApplication::translate("MainWindow", "\346\240\274\345\274\217\357\274\210&O\357\274\211", nullptr));
        menu_V->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\357\274\210&V\357\274\211", nullptr));
        menu_H->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251\357\274\210&H\357\274\211", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
