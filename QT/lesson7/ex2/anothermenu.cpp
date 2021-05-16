#include "anothermenu.h"
#include <QMenu>
#include <QMenuBar>

AnotherMenu::AnotherMenu(QWidget* parent)
    : QMainWindow(parent) {

    // Данные изображения мы будем использовать в качестве иконок в нашем меню
    QPixmap newpix("new.png");
    QPixmap openpix("open.png");
    QPixmap quitpix("quit.png");

    // Здесь в качестве первых аргументов мы используем конструкторы класса QAction
    QAction* newa = new QAction(newpix, "&New", this);
    QAction* open = new QAction(openpix, "&Open", this);
    QAction* quit = new QAction(quitpix, "&Quit", this);

    // А здесь мы задаем сочетание горячих клавиш CTRL+Q, которое будет выполнять действие Quit (Выход)
    quit->setShortcut(tr("CTRL+Q"));

    QMenu* file;
    file = menuBar()->addMenu("&File");
    file->addAction(newa); // добавляем действие "New"
    file->addAction(open); // добавляем действие "Open"
    file->addSeparator(); // устанавливаем разделитель
    file->addAction(quit); // добавляем действие "Quit"

    // В некоторых средах значки меню по умолчанию не отображаются, поэтому мы можем попробовать отключить атрибут Qt::AA_DontShowIconsInMenus
    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);

    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
}