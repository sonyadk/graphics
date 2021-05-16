#include <QTextStream>
#include <QMap>

int main(void) {

    QTextStream out(stdout);

    // Создаем QMap, содержащий 2 пары элементов
    QMap<QString, int> items = { {"coins", 5}, {"books", 3} };

    // С помощью метода insert() добавляем новую пару значений 
    items.insert("bottles", 7);

    // Получаем все значения словаря и выводим их на экран
    QList<int> values = items.values(); // метод values() возвращает список значений словаря
    out << "Values:" << endl;
    for (int val : values) {
        out << val << endl;
    }

    // Аналогично выводим все ключи словаря
    QList<QString> keys = items.keys(); // метод keys() возвращает список, содержащий все ключи в словаре
    out << "Keys:" << endl;
    for (QString key : keys) {
        out << key << endl;
    }

    // Создаем итератор для QMap в Java-стиле
    QMapIterator<QString, int> it(items); // этот итератор может использоваться для итерации по элементам QMap

    out << "Pairs:" << endl;

    // С помощью итератора перебираем все элементы QMap
    while (it.hasNext()) {
        it.next();
        out << it.key() << ": " << it.value() << endl; // метод key() возвращает текущий ключ, а метод value() возвращает текущее значение
    }
}