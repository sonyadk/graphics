#include <QTextStream>
#include <QFileInfo>
#include <QDir>
#include <conio.h>

int main(int argc, char* argv[]) {

    QTextStream out(stdout);
    out.setCodec("cp-866");

    if (argc != 2) {
        qWarning("Usage: list_dir directory");
        return 1;
    }

    QString directory = argv[1];

    // Создаем объект класса QDir с заданным именем каталога
    QDir dir(directory);

    if (!dir.exists()) {
        qWarning("The directory does not exist");
        return 1;
    }

    // Метод setFilter() определяет тип файлов, которые должны быть возвращены методом entryInfoList()
    dir.setFilter(QDir::Files | QDir::AllDirs);

    // Метод setSorting() задает порядок сортировки, используемый методом entryInfoList()
    dir.setSorting(QDir::Size | QDir::Reversed);

    // Метод entryInfoList() возвращает список объектов QFileInfo для всех файлов и папок в каталоге, отфильтрованных и упорядоченных соответствующими методами
    QFileInfoList list = dir.entryInfoList();

    int max_size = 0;

    // Проходимся по списку и определяем максимальный размер имени файла
    foreach(QFileInfo finfo, list) {

        QString name = finfo.fileName();
        int size = name.size();

        if (size > max_size) {
            max_size = size;
        }
    }

    // Добавляем дополнительные два пробела к длине столбца
    int len = max_size + 2;

    // Выводим имена столбцов
    out << QString("Filename").leftJustified(len).append("Bytes") << endl; // метод leftJustified() возвращает строку заданного размера, выравненную по левому краю и дополненную символом заполнения (по умолчанию пробел) справа

    // Просматриваем список файлов и выводим их названия и размеры. Первый столбец выравнивается по левому краю и заполняется пробелами по мере необходимости, затем добавляется второй столбец
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        QString str = fileInfo.fileName().leftJustified(len);
        str.append(QString("%1").arg(fileInfo.size()));
        out << str << endl;
    }

    return 0;
}