
// main.cpp
#include <QApplication>
#include "escaperoom.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    EscapeRoom game;
    game.show();

    return app.exec();
    int globalVariable = 10;

    return 0;
}
