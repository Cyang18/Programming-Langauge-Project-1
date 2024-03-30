#include <iostream>
#include <cmath>

void performMathOperations() 
{
    int a = 100;
    int b = 5;
    int result_addition = a + b;
    int result_subtraction = a - b;
    int result_multiplication = a * b;
    int result_division = a / b;
    int result_exponentiation = pow(a, b);
    double result_sqrt = sqrt(a);

    long c = 1221348482;
    long d = 583747585;

    long result_addition2 = c + d;
    long result_subtraction2 = c - d;
    long result_multiplication2 = c * d;
    long result_division2 = c / d;
    long result_exponentiation2 = pow(c, d);
    double result_sqrt2 = sqrt(d);
    double result3 = sqrt(result_sqrt2);

    double x = 0.5734633;
    double y = 0.3732645;
    double result_addition3 = x + y;
    double result_subtraction3 = x - y;
    double result_multiplication3 = x * y;
    double result_division3 = x / y;
    double result_exponentiation3 = sqrt(x);
    double result_exponentiation4 = sqrt(y);

    double lots_mult = x * x * x * x * y * y * y * y * x * y;
    double lots_add = y + y + y + y + y + y + y + y + y + y + y + x;

    long lots_add2 = c + c + c + c + c + c + d + d + d + d + d + d + d;
    long lots_mult2 = c * c * c * c * c * c * c * c * c * d * d * d * d * d * d;

}

int main() {
    performMathOperations();
    return 0;
}
