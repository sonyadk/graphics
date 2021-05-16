#include <QTextStream>
#include <QDate>
#include <ctime> // подключаем необходимый заголовочный файл

int main() {

	QTextStream out(stdout);
	out.setCodec("CP866"); // устанавливаем CP866-кодировку для консоли
	time_t t = time(0); // получаем Unix-время
	out << t << endl;

	QDateTime dt;
	dt.setTime_t(t); // конвертируем Unix-время в обычный формат даты
	out << dt.toString() << endl;

	QDateTime cd = QDateTime::currentDateTime();
	out << cd.toTime_t() << endl; // метод toTime_t() также может быть использован для получения Unix-времени

	return 0;
}