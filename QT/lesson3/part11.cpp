#include <QTextStream>
#include <QDate>

int main() {

    QTextStream out(stdout);
    out.setCodec("CP866"); // устанавливаем CP866-кодировку для консоли

    // Первые две даты корректны, а вот третья - нет (т.к. февраль может иметь 28 или 29 дней)
    QList<QDate> dates({ QDate(2015, 5, 11), QDate(2015, 8, 1),
       QDate(2015, 2, 30) });

    for (int i = 0; i < dates.size(); i++) {

        // Выводим информацию о корректности проверяемой даты на экран
        if (dates.at(i).isValid()) {
            out << "Date " << i + 1 << " is a valid date" << endl;
        }
        else {
            out << "Date " << i + 1 << " is not a valid date" << endl;
        }
    }
    return 0;
}