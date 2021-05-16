#include <QTextStream>
#include <QDate>
#include <QTime>

int main() {

    QTextStream out(stdout);
    out.setCodec("CP866"); // устанавливаем CP866-кодировку для консоли 

    // Создаем объект даты и помещаем в него год, месяц и день
    QDate dt1(2015, 4, 12);
    out << "The date is " << dt1.toString() << endl; // конвертируем нашу дату в строку и выводим на экран

    QDate dt2;
    dt2.setDate(2015, 3, 3);
    out << "The date is " << dt2.toString() << endl;

    QTime tm1(17, 30, 12, 55);
    out << "The time is " << tm1.toString("hh:mm:ss.zzz") << endl;

    // Создаем пустой объект времени
    QTime tm2;
    tm2.setHMS(13, 52, 45, 155); // передаем часы, минуты, секунды и миллисекунды

    // Выводим время, включая миллисекунды (по умолчанию они не выводятся)
    out << "The time is " << tm2.toString("hh:mm:ss.zzz") << endl;

    return 0;
}