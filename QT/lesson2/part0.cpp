#include <QTextStream> // подключаем необходимый заголовочный файл

int main() {

	QTextStream out(stdout);

	// Создаем строку типа QString
	QString a = "love";

	// Добавляем текст в конец строки
	a.append(" chess");

	// Добавляем текст в начало строки
	a.prepend("I ");

	// Выводим строку
	out << a << endl;

	// Выводим количество символов строки
	out << "The a string has " << a.count() << " characters" << endl;

	// Выводим всю строку в верхнем регистре
	out << a.toUpper() << endl;

	// Выводим всю строку в нижнем регистре
	out << a.toLower() << endl;

	return 0;
}