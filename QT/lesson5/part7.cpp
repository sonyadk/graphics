#include <QTextStream>
#include <QDir>
#include <conio.h>

int main() {

    QTextStream out(stdout);
    out.setCodec("cp-866");
    QDir dir;

    // Метод mkdir() создает каталог, при этом возвращая true, если каталог был успешно создан
    if (dir.mkdir("mydir")) {
        out << "mydir successfully created" << endl;
    }

    dir.mkdir("mydir2");

    // Метод exists() проверяет наличие каталога
    if (dir.exists("mydir2")) {
        dir.rename("mydir2", "newdir"); // метод rename() переименовывает каталог  
    }

    // Создаем новый каталог и все необходимые родительские каталоги
    dir.mkpath("temp/newdir");
}