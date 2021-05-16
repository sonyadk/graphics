#include <QTextStream>
#include <QDate>

int main() {

	QTextStream out(stdout);
	out.setCodec("CP866"); // устанавливаем CP866-кодировку для консоли
	QDateTime cdt = QDateTime::currentDateTime();

	// Получаем время в формате UTC, конвертируем его в строку и выводим на экран
	out << "Universal datetime: " << cdt.toUTC().toString() << endl;

	// Получаем локальное время, конвертируем его в строку и выводим на экран
	out << "Local datetime: " << cdt.toLocalTime().toString() << endl;

	return 0;
}