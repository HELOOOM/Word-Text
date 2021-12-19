#include "wordtext.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    wordtext w;
    w.show();
    return a.exec();
}
