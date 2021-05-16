#include <QVector>
#include <QTextStream>

int main(void) {

    QTextStream out(stdout);

    // Создаем вектор, содержащий целочисленные значения
    QVector<int> vals = { 1, 2, 3, 4, 5 };

    // С помощью метода size() возвращаем размер вектора (количество элементов, содержащихся в нем)
    out << "The size of the vector is: " << vals.size() << endl;

    out << "The first item is: " << vals.first() << endl; // получаем первый элемент вектора
    out << "The last item is: " << vals.last() << endl; // получаем последний элемент вектора

    vals.append(6); // вставляем новый элемент в конец вектора
    vals.prepend(0); // вставляем новый элемент в начало вектора

    out << "Elements: ";

    // Перебираем элементы вектора и выводим их на экран
    for (int val : vals) {
        out << val << " ";
    }

    out << endl;

    return 0;
}