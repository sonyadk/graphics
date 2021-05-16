#include <QTextStream>
#include <QList>
#include <algorithm>

int main(void) {

    QTextStream out(stdout);

    // Создаем контейнер QList, в котором будем хранить имена писателей
    QList<QString> authors = { "Balzac", "Tolstoy",
        "Gulbranssen", "London" };

    // Перебираем каждый элемент массива и выводим на экран
    for (int i = 0; i < authors.size(); ++i) {

        out << authors.at(i) << endl; // метод at() возвращает элемент с указанным индексом
    }

    // С помощью оператора << вставляем в список 2 новых элемента
    authors << "Galsworthy" << "Sienkiewicz";

    out << "***********************" << endl;

    // С помощью метода sort() сортируем список в порядке возрастания
    std::sort(authors.begin(), authors.end());

    // Выводим на экран отсортированный список
    out << "Sorted:" << endl;
    for (QString author : authors) {

        out << author << endl;
    }
}