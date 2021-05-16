#include <QTextStream>
#include <QFileInfo>
#include <conio.h>

int main(int argc, char* argv[]) {

    QTextStream out(stdout);
    out.setCodec("cp-866");

    if (argc != 2) {
        out << "Usage: file_times file" << endl;
        return 1;
    }

    QString filename = argv[1];

    // Определяем путь к файлу
    QFileInfo fileinfo(filename);

    QString absPath = fileinfo.absoluteFilePath(); // возвращаем абсолютный путь, включающий имя файла
    QString baseName = fileinfo.baseName(); // возвращаем базовое имя: имя файла без пути
    QString compBaseName = fileinfo.completeBaseName(); // возвращаем полное базовое имя: все символы в имени файла до последней точки (но не включая её)
    QString fileName = fileinfo.fileName(); // возвращаем имя файла, которое является базовым именем + расширение
    QString suffix = fileinfo.suffix(); // возвращаем расширение файла, которое состоит из всех символов в базовом имени файла + расширение после последнего символа точки (но не включая её)
    QString compSuffix = fileinfo.completeSuffix(); // возвращаем расширение файла, которое состоит из всех символов в базовом имени файла + расширение после первого символа точки (но не включая её)

    out << "Absolute file path: " << absPath << endl;
    out << "Base name: " << baseName << endl;
    out << "Complete base name: " << compBaseName << endl;
    out << "File name: " << fileName << endl;
    out << "Suffix: " << suffix << endl;
    out << "Whole suffix: " << compSuffix << endl;
}