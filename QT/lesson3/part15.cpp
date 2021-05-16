#include <QTextStream>
#include <QDate>

int main() {

	QTextStream out(stdout);
	out.setCodec("CP866"); // устанавливаем CP866-кодировку для консоли

	// Ниже представлены 2 даты битв из Наполеоновской эпохи
	QDate bordate(1812, 9, 7);
	QDate slavdate(1805, 12, 2);

	QDate cd = QDate::currentDate();

	// Теперь вычисляем, сколько Юлианских дней на текущий момент прошло от начала Юлианского периода до текущего момента и до дат битв за Славков и Бородино
	int j_today = cd.toJulianDay();
	int j_borodino = bordate.toJulianDay();
	int j_slavkov = slavdate.toJulianDay();

	// Теперь посчитаем, сколько дней прошло от каждого из двух вышеприведенных событий до настоящего момента
	out << "Days since Slavkov battle: " << j_today - j_slavkov << endl;
	out << "Days since Borodino battle: " << j_today - j_borodino << endl;

	return 0;
}