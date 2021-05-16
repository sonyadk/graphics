#include <QTextStream>

int main() {

	QTextStream out(stdout);

	// Исходная строка
	QString a = "Eagle";

	// Выводим первый символ строки
	out << a[0] << endl;

	// Выводим пятый символ строки
	out << a[4] << endl;

	// Выводим первый символ строки с помощью метода at()
	out << a.at(0) << endl;

	return 0;
}