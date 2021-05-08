/*
Измените программу из задания №2 так, чтобы она использовала заголовочный файл io.h 
для доступа к функциям (вместо использования предварительных объявлений). 
Убедитесь, что ваш заголовочный файл использует header guards.
*/

#include <iostream>

int readNumber(){
  std:cout <<"Введите число: " << std::endl;
  std::cin >> number;
  return number;
}

void writeAnswer(int result){
  std:cout <<"Результат: " << result <<std::endl;
}
