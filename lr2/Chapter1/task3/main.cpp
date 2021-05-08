/*
Измените программу из задания №2 так, чтобы она использовала заголовочный файл io.h 
для доступа к функциям (вместо использования предварительных объявлений). 
Убедитесь, что ваш заголовочный файл использует header guards.
*/

#include "io.h"

int main(){
  num_1 = readNumber();
  num_2 = readNumber();
  result = num_1 + num_2;
  writeAnswer(result);
  return result;
}
