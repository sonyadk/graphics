#include <QTextStream>
#include <QDate>

int main() {

    QTextStream out(stdout);
    out.setCodec("CP866"); // устанавливаем CP866-кодировку для консоли
    QDate dt(2019, 5, 11); // указываем дату
    QDate nd = dt.addDays(55); // возвращаем дату через 55 дней после указанной выше даты

    QDate xmas(2019, 12, 24);

    out << "55 days from " << dt.toString() << " is "
        << nd.toString() << endl;
    out << "There are " << QDate::currentDate().daysTo(xmas) // возвращаем количество дней до наступления Рождества
        << " days till Christmas" << endl;
    return 0;
}