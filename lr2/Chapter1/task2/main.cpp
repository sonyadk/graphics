/*
Измените программу из задания №1 так, чтобы функции readNumber() и writeAnswer() 
находились в отдельном файле io.cpp. Используйте предварительные объявления 
для доступа к этим функциям с функции main().
*/

int readNumber();
void writeAnswer(int x);

int main(){
  num_1 = readNumber();
  num_2 = readNumber();
  result = num_1 + num_2;
  writeAnswer(result);
  return result;
}
