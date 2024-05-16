#pragma once

#include "docwindow.h"
#include <QtWidgets>

class SDIProgram : public QMainWindow {
Q_OBJECT
public:
    explicit SDIProgram(QWidget *parent = nullptr);

public slots:
    void slotAbout();
    void slotChangeWindowTitle(const QString& str);
};

