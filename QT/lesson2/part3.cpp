#include <QTextStream>

int main() {

	QTextStream out(stdout);

	// Обычная строка
	QString s1 = "Eagle";

	// Здесь у нас символ новой строки
	QString s2 = "Eagle\n";

	// Здесь у нас пробел в конце строки
	QString s3 = "Eagle ";

	// А это вообще кириллица
	QString s4 = "орел";

	out << s1.length() << endl;
	out << s2.length() << endl;
	out << s3.length() << endl;
	out << s4.length() << endl;

	return 0;
}