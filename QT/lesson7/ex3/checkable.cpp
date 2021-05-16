#include "checkable.h"
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>

Checkable::Checkable(QWidget * parent)
    : QMainWindow(parent) {

    // Создаем действие (пункт) "View statusbar" в меню
    viewst = new QAction("&View statusbar", this);

    // Делаем так, чтобы этот пункт меню можно было отметить галочкой
    viewst->setCheckable(true);

    // Делаем этот пункт меню отмеченным галочкой по умолчанию
    viewst->setChecked(true);

    QMenu* file;
    file = menuBar()->addMenu("&File");
    file->addAction(viewst);

    statusBar();

    connect(viewst, &QAction::triggered, this, &Checkable::toggleStatusbar);
}

void Checkable::toggleStatusbar() {

    // Определяем, установлен ли флажок для элемента меню, и, исходя из этого, скрываем или показываем строку состояния
    if (viewst->isChecked()) {
        statusBar()->show();
    }
    else {
        statusBar()->hide();
    }
}