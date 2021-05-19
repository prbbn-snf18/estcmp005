/*
1) Faça um programa que receba dois números inteiros e gere os números
inteiros que estão no intervalo compreendido por eles.
*/
#include <iostream>
using namespace std;

int main() {

    int a, b = 0;
    cout << "Digite dois numeros: \n";
    cin >> a >> b;
    cout << endl;
    
    if (a > b){
        for (int i = 1; i < (a-b); i++) cout << i+b << endl;
    }else if(b > a){
        for (int i = 1; i < (b-a); i++) cout << i+a << endl;
    }else cout << a-b;

    return 0;
}