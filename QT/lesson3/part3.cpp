#include <QTextStream>
#include <QTime>
#include <QDate>

int main() {

    QTextStream out(stdout);
    out.setCodec("CP866"); // устанавливаем CP866-кодировку для консоли

    // Создаем 2 объекта с датами
    QDate dt1(2015, 4, 5);
    QDate dt2(2014, 4, 5);

    // Сравниваем даты и определяем, какая из них расположена раньше в календаре
    if (dt1 < dt2) {
        out << dt1.toString() << " comes before "
            << dt2.toString() << endl;
    }
    else {
        out << dt1.toString() << " comes after "
            << dt2.toString() << endl;
    }

    return 0;
}