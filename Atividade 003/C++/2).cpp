/*2) Faça um Programa que peça dois números e imprima o maior deles.*/
#include <iostream>
using namespace std;

int main() {

    int a, b = 0;
    cout << "Digite dois numeros:\n";
    cin >> a >> b;
    cout << endl;

    if(a > b) cout << a;
    else cout << b;

    return 0;
}