/*
Задание №3

Напишите следующую программу. Сначала пользователю предлагается ввести 2 числа типа с плавающей точкой (используйте тип double). Затем предлагается ввести один из следующих математических символов: +, -, * или /. Программа выполняет выбранную пользователем математическую операцию между двумя числами, а затем выводит результат на экран. Если пользователь ввел некорректный символ, то программа ничего не должна выводить.
*/

#include <iostream>
 
double getDouble()
{
    std::cout << "Введите значения: ";
    double x;
    std::cin >> x;
    return x;
}
 
char getOperator()
{
    std::cout << "Выберите символ: +, -, *, или / ";
    char op;
    std::cin >> op;
    return op;
}
 
void printResult(double x, char op, double y)
{
    if (op == '+')
        std::cout << x << " + " << y << " = " << x + y << '\n';
    else if (op == '-')
        std::cout << x << " - " << y << " = " << x - y << '\n';
    else if (op == '*')
        std::cout << x << " * " << y << " = " << x * y << '\n';
    else if (op == '/')
        std::cout << x << " / " << y << " = " << x / y << '\n';
}
 
int main()
{
    double x = getDouble();
    double y = getDouble();
 
    char op = getOperator();
 
    printResult(x, op, y);
 
    return 0;
}
