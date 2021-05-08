/*
    Задание №1
    
    Напишите однофайловую программу (с именем main.cpp), которая запрашивает у пользователя
    два целых числа, складывает их, а затем выводит результат.
    В программе должно быть 3 функции:
    - функция readNumber(), которая запрашивает у пользователя целое число, а затем возвращает его в main();
    - функция writeAnswer(), которая выводит результат на экран. Функция должна быть без возвращаемого
    значения и иметь только один параметр;
    - функция main(), которая соединяет всё и вся.
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
    
    int main(){
      num_1 = readNumber();
      num_2 = readNumber();
      result = num_1 + num_2;
      writeAnswer(result);
      return result;
    }
