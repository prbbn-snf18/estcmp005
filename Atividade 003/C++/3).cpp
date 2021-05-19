/*
Faça um Programa que peça a temperatura em graus Fahrenheit,
transforme e mostre a temperatura em graus Celsius.
C = 5 * ((F-32) / 9).
*/
#include <iostream>
using namespace std;

int main() {
    
    int a = 0;
    cout << "Digite uma temperatura em farenheit para ser convertida em celsius:\n";
    cin >> a;
    cout << endl;

    cout << 5 * ((a-32) / 9) << "C";
    return 0;
}