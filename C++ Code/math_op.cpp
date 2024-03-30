#include <iostream>
#include <cmath>

using namespace std;

void performMathOperations() {
    int a = 100;
    int b = 5;
    int result_addition = a + b;
    int result_subtraction = a - b;
    int result_multiplication = a * b;
    int result_division = a / b;
    int result_exponentiation = pow(a, b);
    double result_sqrt = sqrt(static_cast<double>(a));

    long c = 1221348482;
    long d = 583747585;

    long result_addition2 = c + d;
    long result_subtraction2 = c - d;
    long result_multiplication2 = c * d;
    long result_division2 = c / d;
    long result_exponentiation2 = pow(c, d);
    double result_sqrt2 = sqrt(static_cast<double>(d));
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

    cout << "Result Addition: " << result_addition << endl;
    cout << "Result Subtraction: " << result_subtraction << endl;
    cout << "Result Multiplication: " << result_multiplication << endl;
    cout << "Result Division: " << result_division << endl;
    cout << "Result Exponentiation: " << result_exponentiation << endl;
    cout << "Result Square Root: " << result_sqrt << endl;
    cout << "Result Addition 2: " << result_addition2 << endl;
    cout << "Result Subtraction 2: " << result_subtraction2 << endl;
    cout << "Result Multiplication 2: " << result_multiplication2 << endl;
    cout << "Result Division 2: " << result_division2 << endl;
    cout << "Result Exponentiation 2: " << result_exponentiation2 << endl;
    cout << "Result Square Root 2: " << result_sqrt2 << endl;
    cout << "Result 3: " << result3 << endl;
    cout << "Result Addition 3: " << result_addition3 << endl;
    cout << "Result Subtraction 3: " << result_subtraction3 << endl;
    cout << "Result Multiplication 3: " << result_multiplication3 << endl;
    cout << "Result Division 3: " << result_division3 << endl;
    cout << "Result Exponentiation 3: " << result_exponentiation3 << endl;
    cout << "Result Exponentiation 4: " << result_exponentiation4 << endl;
    cout << "Lots Mult: " << lots_mult << endl;
    cout << "Lots Add: " << lots_add << endl;
    cout << "Lots Add 2: " << lots_add2 << endl;
    cout << "Lots Mult 2: " << lots_mult2 << endl;
}

int main() {
    performMathOperations();
    return 0;
}
