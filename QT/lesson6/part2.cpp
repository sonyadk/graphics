#include <QApplication>
#include <QWidget>

int main(int argc, char* argv[]) {

	QApplication app(argc, argv);

	QWidget window;

	window.resize(250, 150);
	window.move(300, 300);
	window.setWindowTitle("ToolTip"); // устанавливаем заголовок для окна
	window.setToolTip("QWidget"); // устанавливаем всплывающую подсказку для виджета
	window.show(); // выводим на экран

	return app.exec();
}