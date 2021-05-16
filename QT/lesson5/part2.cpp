#include <QTextStream>
#include <QFile>

int main() {

    QTextStream out(stdout);

    // Создаем объект
    QFile file("C:\\colours.txt");

    // С помощью метода open() открываем файл в режиме чтения
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading"); // если файл не найден, то выводим предупреждение и завершаем выполнение программы
        return 1;
    }

    // Создаем входящий поток, из которого будут считываться данные, и связываем его с нашим файлом
    QTextStream in(&file);

    // Считываем файл строка за строкой
    while (!in.atEnd()) { // метод atEnd() возвращает true, если в потоке больше нет данных для чтения
        QString line = in.readLine(); // метод readLine() считывает одну строку из потока
        out << line << endl;
    }

    // Закрываем файл 
    file.close();
}