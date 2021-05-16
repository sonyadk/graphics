#include <QTextStream>

int main() {

	QTextStream out(stdout);

	// Инициализация №1: Традиционный вариант
	QString str1 = "The night train";
	out << str1 << endl;

	// Инициализация №2: Объектный способ
	QString str2("A yellow rose");
	out << str2 << endl;

	// Инициализация №3 
	std::string s1 = "A blue sky";
	QString str3 = s1.c_str();
	out << str3 << endl;

	// Инициализация №4 
	std::string s2 = "A thick fog";
	QString str4 = QString::fromLatin1(s2.data(), s2.size());
	out << str4 << endl;

	// Инициализация №5
	char s3[] = "A deep forest";
	QString str5(s3);
	out << str5 << endl;

	return 0;
}