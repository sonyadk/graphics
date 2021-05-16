#include <QTextStream>
#include <QDate>

int main() {

	QTextStream out(stdout);
	out.setCodec("CP866"); // устанавливаем CP866-кодировку для консоли

	QDate cd = QDate::currentDate();

	out << "Today is " << cd.toString(Qt::TextDate) << endl;
	out << "Today is " << cd.toString(Qt::ISODate) << endl; // используем международный стандарт вывода даты
	out << "Today is " << cd.toString(Qt::SystemLocaleShortDate) << endl;
	out << "Today is " << cd.toString(Qt::SystemLocaleLongDate) << endl;
	out << "Today is " << cd.toString(Qt::DefaultLocaleShortDate) << endl;
	out << "Today is " << cd.toString(Qt::DefaultLocaleLongDate) << endl;
	out << "Today is " << cd.toString(Qt::SystemLocaleDate) << endl;
	out << "Today is " << cd.toString(Qt::LocaleDate) << endl;

	return 0;
}