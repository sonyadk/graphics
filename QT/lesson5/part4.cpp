#include <QTextStream>
#include <QFile>
#include <conio.h>

int main(int argc, char* argv[]) {

    QTextStream out(stdout);
    out.setCodec("cp-866");

    // Программа принимает 2 параметра
    if (argc != 3) {
        qWarning("Usage: copyfile source destination"); // если параметров нет, то выводится предупреждение
        return 1;
    }

    // Из аргументов командной строки программы мы получаем имя исходного файла
    QString source = argv[1];

    // Проверяем наличие исходного файла 
    if (!QFile(source).exists()) {
        qWarning("The source file does not exist"); // если файл не найден, то выводим предупреждение и завершаем выполнение программы
        return 1;
    }

    // Получаем имя файла назначения
    QString destin(argv[2]);

    // Копируем исходный файл
    QFile::copy(source, destin); // первый параметр - это имя исходного файла, а второй - имя конечного файла
}