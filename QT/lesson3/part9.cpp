#include <QTextStream>
#include <QDate>


int main() {

	QTextStream out(stdout);
	out.setCodec("CP866"); // устанавливаем CP866-кодировку для консоли

	// Получаем текущую дату
	QDate cd = QDate::currentDate();
	int wd = cd.dayOfWeek(); // определяем название дня недели

	QLocale loc;

	out << "Today is " << QDate::shortDayName(wd) << endl; // выводим короткое название дня недели
	out << "Today is " << QDate::longDayName(wd) << endl; // выводим полное название дня недели

	return 0;
}