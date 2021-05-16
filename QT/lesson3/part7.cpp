#include <QTextStream>
#include <QDate>

int main() {

	QTextStream out(stdout);
	out.setCodec("CP866"); // устанавливаем CP866-кодировку для консоли

	QTime ct = QTime::currentTime();

	out << "The time is " << ct.toString(Qt::TextDate) << endl;
	out << "The time is " << ct.toString(Qt::ISODate) << endl;
	out << "The time is " << ct.toString(Qt::SystemLocaleShortDate) << endl;
	out << "The time is " << ct.toString(Qt::SystemLocaleLongDate) << endl;
	out << "The time is " << ct.toString(Qt::DefaultLocaleShortDate) << endl;
	out << "The time is " << ct.toString(Qt::DefaultLocaleLongDate) << endl;
	out << "The time is " << ct.toString(Qt::SystemLocaleDate) << endl;
	out << "The time is " << ct.toString(Qt::LocaleDate) << endl;

	return 0;
}