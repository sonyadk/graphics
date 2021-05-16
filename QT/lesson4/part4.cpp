#include <QSet>
#include <QList>
#include <QTextStream>
#include <algorithm>

int main(void) {

    QTextStream out(stdout);

    // Создаем 2 набора цветов 
    QSet<QString> cols1 = { "yellow", "red", "blue" };
    QSet<QString> cols2 = { "blue", "pink", "orange" };

    // С помощью метода size() возвращаем размер набора
    out << "There are " << cols1.size() << " values in the set" << endl;

    // С помощью метода insert() вставляем новый элемент
    cols1.insert("brown");

    out << "There are " << cols1.size() << " values in the set" << endl;

    // Метод unite() выполняет объединение двух наборов
    cols1.unite(cols2);

    out << "There are " << cols1.size() << " values in the set" << endl;

    // Перебираем все элементы набора cols1 и выводим их на экран
    for (QString val : cols1) {
        out << val << endl;
    }

    // Создаем отдельный список из набора элементов cols1 для их сортировки
    QList<QString> lcols = cols1.values(); // метод values() возвращает новый QList, содержащий элементы набора
    std::sort(lcols.begin(), lcols.end());

    out << "*********************" << endl;
    out << "Sorted:" << endl;

    for (QString val : lcols) {
        out << val << endl;
    }

    return 0;
}