#include <QTextStream>
#include <QDate>

int main() {

	QTextStream out(stdout);
	out.setCodec("CP866"); // устанавливаем CP866-кодировку для консоли

	QDate cd = QDate::currentDate();

	out << "Today is " << cd.toString("yyyy-MM-dd") << endl; // в качестве разделителя используем дефис
	out << "Today is " << cd.toString("yy/M/dd") << endl; // в качестве разделителя используем слэш
	out << "Today is " << cd.toString("d. M. yyyy") << endl; // в качестве разделителя используем точку
	out << "Today is " << cd.toString("d-MMMM-yyyy") << endl; // в качестве разделителя используем дефис

	return 0;
}