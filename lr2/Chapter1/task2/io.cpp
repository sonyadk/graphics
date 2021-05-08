/*
Измените программу из задания №1 так, чтобы функции readNumber() и writeAnswer() 
находились в отдельном файле io.cpp. Используйте предварительные объявления для 
доступа к этим функциям с функции main().
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
