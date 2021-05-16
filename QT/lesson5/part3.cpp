#include <QTextStream>
#include <QFile>

int main() {

    QTextStream out(stdout);

    // Создаем объект класса QFile и связываем его с указанным именем файла
    QString filename = "C:\\distros.txt";
    QFile file(filename);

    // Открываем файл в режиме "Только для записи"
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file); // поток записываемых данных направляем в файл

        // Для записи данных в файл используем оператор <<
        out << "Xubuntu" << endl;
        out << "Arch" << endl;
        out << "Debian" << endl;
        out << "Redhat" << endl;
        out << "Slackware" << endl;

    }
    else {

        qWarning("Could not open file");
    }

    // Закрываем файл
    file.close();
}