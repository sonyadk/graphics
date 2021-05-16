#include <QTextStream>

int main() {

    QTextStream out(stdout);

    QString str = "There are many stars.";

    // Способ №1
    foreach(QChar qc, str) {
        out << qc << " ";
    }

    out << endl;

    // Способ №2
    for (QChar* it = str.begin(); it != str.end(); ++it) {
        out << *it << " ";
    }

    out << endl;

    // Способ №3
    for (int i = 0; i < str.size(); ++i) {
        out << str.at(i) << " ";
    }

    out << endl;

    return 0;
}