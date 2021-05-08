/*
Задание №4
Напишите небольшую программу-симулятор падения мячика с башни. Сначала пользователю предлагается ввести высоту башни в метрах. Не забывайте о гравитации (9,8м/с2) и о том, что у мячика нет начальной скорости (его держат в руках). Программа должна выводить расстояние от земли, на котором находится мячик после 0, 1, 2, 3, 4 и 5 секунд падения. Минимальная высота составляет 0 метров (ниже мячику падать нельзя).
*/

#include <iostream>
#include "constants.h"

using namespace std;
using namespace myConstants;

double getInitialHeight() {
	cout << "Enter the initial height of the tower in meters: ";
	double initialHeight;
	cin >> initialHeight;

	return initialHeight;
}

double calculateHeight(double initialHeight, int seconds) {
  double dist = (gravity * seconds * seconds) / 2;
  double currentHeight = initialHeight - dist;

  return currentHeight;
}

void printHeight(double height, int seconds) {
  if (height > 0.0) {
    cout << seconds << " sec: the ball is at " << height << " meters" << endl;
  } else {
    cout << seconds << " sec: the ball is on the ground.." << endl;
  }
}

void calculateAndPrintHeight(double initialHeight, int seconds)
{
	double height = calculateHeight(initialHeight, seconds);
	printHeight(height, seconds);
}

int main() {
  const double initialHeight = getInitialHeight();

  calculateAndPrintHeight(initialHeight, 0);
	calculateAndPrintHeight(initialHeight, 1);
	calculateAndPrintHeight(initialHeight, 2);
	calculateAndPrintHeight(initialHeight, 3);
	calculateAndPrintHeight(initialHeight, 4);
	calculateAndPrintHeight(initialHeight, 5);

  return 0;
}
