#include <QTextStream>
#include <QDate>

int main() {

    QTextStream out(stdout);
    out.setCodec("CP866"); // устанавливаем CP866-кодировку для консоли
    QDate cd = QDate::currentDate();

    out << "Gregorian date for today: " << cd.toString(Qt::ISODate) << endl; // выводим Григорианскую дату
    out << "Julian day for today: " << cd.toJulianDay() << endl; // выводим Юлианский день    

    return 0;
}