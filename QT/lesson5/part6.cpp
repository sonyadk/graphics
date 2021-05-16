#include <QTextStream>
#include <QFileInfo>
#include <QDateTime>
#include <conio.h>

int main(int argc, char* argv[]) {

    QTextStream out(stdout);
    out.setCodec("cp-866");

    if (argc != 2) {
        qWarning("Usage: file_times file");
        return 1;
    }

    QString filename = argv[1];

    // Создаем объект класса QFileInfo. В качестве параметра используем имя файла из аргумента командной строки
    QFileInfo fileinfo(filename);

    // Определяем дату и время последнего чтения файла
    QDateTime last_rea = fileinfo.lastRead();

    // Определяем дату и время последнего изменения файла
    QDateTime last_mod = fileinfo.lastModified();

    out << "Last read: " << last_rea.toString() << endl;
    out << "Last modified: " << last_mod.toString() << endl;
}