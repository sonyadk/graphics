/*
Задание №4
Напишите небольшую программу-симулятор падения мячика с башни. Сначала пользователю предлагается ввести высоту башни в метрах. Не забывайте о гравитации (9,8м/с2) и о том, что у мячика нет начальной скорости (его держат в руках). Программа должна выводить расстояние от земли, на котором находится мячик после 0, 1, 2, 3, 4 и 5 секунд падения. Минимальная высота составляет 0 метров (ниже мячику падать нельзя).
*/

  
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace myConstants {
  const double gravity(9.8); 
}

#endif
