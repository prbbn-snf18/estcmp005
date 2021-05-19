/*
4) Faça um programa que resolva a MÉDIA DA UEA
*/
#include <iostream>
using namespace std;

int main() {

    float ap1, ap2 = 0;

    cout << "Digite a primeira media (AP1): ";
    cin >> ap1;
    cout << "DIgite a segunda media (AP2): ";
    cin >> ap2;

    float mp, pf = 0;
    mp = (ap1 + ap2)/2;
    cout << "Media parcial: " << mp;

    if(mp < 8){
        cout << "\nDigite a noat da prova final:  ";
        cin >> pf;
        pf = ((mp * 2) + pf) / 3;
        cout << "\nMedia final: " << pf;

        if (pf > 6) cout << "\nAprovado!";
        else cout << "\nReprovado.";
    } else cout << "\nAprovado direto!";

    return 0;
}