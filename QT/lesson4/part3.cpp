#include <QTextStream>
#include <QList>

int main(void) {

    QTextStream out(stdout);

    QString string = "coin, book, cup, pencil, clock, bookmark";

    // С помощью метода split() разделяем строку на подстроки 
    QStringList items = string.split(",");

    // Это константный итератор в Java-стиле для QStringList
    QStringListIterator it(items);

    // С помощью созданного итератора выводим элементы списка на экран 
    while (it.hasNext()) {
        out << it.next().trimmed() << endl; // с помощью метода trimmed() удаляем пробелы из строки    
    }
}