#include <QTextStream>
#include <QDate>

int main() {

    QTextStream out(stdout);
    out.setCodec("CP866"); // устанавливаем CP866-кодировку для консоли
    QDateTime cdt = QDateTime::currentDateTime();

    out << "The current datetime is " << cdt.toString() << endl; // выводим полную дату со временем
    out << "The current date is " << cdt.date().toString() << endl; // выводим только дату
    out << "The current time is " << cdt.time().toString() << endl; // выводим только время

    return 0;
}