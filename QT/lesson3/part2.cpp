#include <QTextStream>
#include <QTime>
#include <QDate>

int main() {

    QTextStream out(stdout);
    out.setCodec("CP866"); // устанавливаем CP866-кодировку для консоли

    QDate cd = QDate::currentDate(); // возвращаем текущую дату
    QTime ct = QTime::currentTime(); // возвращаем текущее время

    // Выполняем конвертацию даты и времени в строки и выводим их
    out << "Current date is: " << cd.toString() << endl;
    out << "Current time is: " << ct.toString() << endl;

    return 0;
}