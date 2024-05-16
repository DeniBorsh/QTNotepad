#include "sdiprogram.h"

SDIProgram::SDIProgram(QWidget *parent) : QMainWindow{parent} {
    QMenu* fileMenu = new QMenu("&File");
    QMenu* helpMenu = new QMenu("&Help");
    DocWindow* doc = new DocWindow;

    fileMenu->addAction("&Open...",
                        doc,
                        SLOT(load()),
                        QKeySequence("CTRL+O"));
    fileMenu->addAction("&Save",
                        doc,
                        SLOT(save()),
                        QKeySequence("CTRL+S"));
    fileMenu->addAction("&Save As...",
                        doc,
                        SLOT(saveAs()));
    fileMenu->addSeparator();
    fileMenu->addAction("&Quit",
                        qApp,
                        SLOT(quit()),
                        QKeySequence("CTRL+Q"));
    helpMenu->addAction("&About",
                        this,
                        SLOT(slotAbout()),
                        Qt::Key_F1);
    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(helpMenu);

    setCentralWidget(doc);

    connect(doc, SIGNAL(changeWindowTitle(const QString&)), SLOT(slotChangeWindowTitle(const QString&)));
    statusBar()->showMessage("Ready", 2000);
}

void SDIProgram::slotAbout() {
    QMessageBox::about(this, "Application", "SDI Example");
}

void SDIProgram::slotChangeWindowTitle(const QString& str) {
    setWindowTitle(str);
}
