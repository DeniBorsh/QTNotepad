#include "sdiprogram.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SDIProgram notepad;

    notepad.resize(600, 400);

    notepad.show();
    return a.exec();
}
