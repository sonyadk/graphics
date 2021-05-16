#include <QTextStream>
#include <QDate>

int main() {

    QTextStream out(stdout);
    out.setCodec("CP866"); // устанавливаем CP866-кодировку для консоли

    // Инициализация списка лет
    QList<int> years({ 2010, 2011, 2012, 2013, 2014, 2015, 2016 });

    // Перебираем все элементы списка и вычисляем високосные года     
    foreach(int year, years) {
        if (QDate::isLeapYear(year)) {
            out << year << " is a leap year" << endl;
        }
        else {
            out << year << " is not a leap year" << endl;
        }
    }
    return 0;
}