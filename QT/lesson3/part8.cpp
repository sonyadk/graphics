#include <QTextStream>
#include <QDate>

int main() {

	QTextStream out(stdout);
	out.setCodec("CP866"); // устанавливаем CP866-кодировку для консоли

	QTime ct = QTime::currentTime();

	out << "The time is " << ct.toString("hh:mm:ss.zzz") << endl; // добавили вывод миллисекунд
	out << "The time is " << QLocale("Russian").toString(ct, "h:m:s a") << endl; // добавили идентификаторы "am/pm" (до полудня/после полудня)
	out << "The time is " << QLocale("Russian").toString(ct, "H:m:s A") << endl; // добавили идентификаторы "AM/PM" (До полудня/После полудня)
	out << "The time is " << QLocale("Russian").toString(ct, "h:m AP") << endl; // добавили идентификаторы "AM/PM" (До полудня/После полудня)

	out << "The version of Qt5 is " << qVersion() << endl;

	return 0;
}