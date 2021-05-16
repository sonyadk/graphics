#include <QTextStream>
#include <QDir>
#include <conio.h>

int main() {

    QTextStream out(stdout);
    out.setCodec("cp-866");

    out << "Current path:" << QDir::currentPath() << endl; // определяем и выводим путь текущего рабочего каталога
    out << "Home path:" << QDir::homePath() << endl; // определяем и выводим путь домашнего каталога
    out << "Temporary path:" << QDir::tempPath() << endl; // определяем и выводим путь временного каталога
    out << "Rooth path:" << QDir::rootPath() << endl; // определяем и выводим путь корневого каталога
}