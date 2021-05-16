#include <QTextStream>
#include <QFileInfo>

int main(int argc, char* argv[]) {

    QTextStream out(stdout);

    if (argc != 2) {

        qWarning("Usage: file_size file");
        return 1;
    }

    // Имя файла передается в качестве аргумента в нашу программу
    QString filename = argv[1];

    // Проверяем существование файла 
    if (!QFile(filename).exists()) {
        qWarning("The file does not exist"); // если файл не найден, то выводим предупреждение и завершаем работу программы
        return 1;
    }

    // Создаем объект 
    QFileInfo fileinfo(filename);

    // Определяем размер файла с помощью метода size() 
    qint64 size = fileinfo.size(); // qint64 - это тип данных, который гарантированно будет 64-битным на всех платформах, поддерживаемых Qt

    // Выводим результат
    QString str = "The size is: %1 bytes";
    out << str.arg(size) << endl;
}