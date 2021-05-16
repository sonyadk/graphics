#include <QTextStream>
#include <QFileInfo>

int main(int argc, char* argv[]) {

    extern Q_CORE_EXPORT int qt_ntfs_permission_lookup;
    qt_ntfs_permission_lookup++; // включение проверки

    QTextStream out(stdout);

    if (argc != 2) {
        qWarning("Usage: owner file");
        return 1;
    }

    QString filename = argv[1];

    // Создаем объект класса QFileInfo. В качестве параметра используем имя файла из аргумента командной строки
    QFileInfo fileinfo(filename);

    // Определяем основную группу файла
    QString group = fileinfo.group();

    // Определяем владельца файла
    QString owner = fileinfo.owner();

    out << "Group: " << group << endl;
    out << "Owner: " << owner << endl;
}