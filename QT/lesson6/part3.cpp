#include <QApplication>
#include <QWidget>
#include <QIcon>

int main(int argc, char* argv[]) {

    QApplication app(argc, argv);

    QWidget window;

    window.resize(250, 150);
    window.setWindowTitle("Icon");
    window.setWindowIcon(QIcon("web.png"));
    window.show();

    return app.exec();
}