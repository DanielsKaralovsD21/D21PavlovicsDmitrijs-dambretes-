#include <iostream>
#include <windows.h>
#include "menu.h"
#include "board.h"
#include "gameplay.h"
using namespace std;


void menu()
{
    system("cls");
    cout << "DAMBRETES" << endl;
    cout << endl;
    cout << "1 - spelet" << endl;
    cout << "2 - ka spelet" << endl;
    cout << "0 - izeja" << endl;

}



void tutorial()
{

    int atkartot;

    do{
        system("cls");
        cout << " Pirmo gajienu izdara speletajs, kuram ir baltie kaulini" << endl << " Abi speletaji gajienus veic parmainus." << endl;
        cout << " Parasta gajiena kaulini var virzities tikai uz prieksu par vienu laucinu"<< endl << " kas atrodas diagonali uz prieksu pa labi vai pa kreisi un nav aiznemts ar citu kaulinu" << endl;
        cout << " Ja kaulins ar parasto gajienu vai sitiena beigas sasniedz talako malu, tas parversas par damu" << endl << " Damu apzime ar lielu burtu W vai B" << endl;
        cout << " Lai izdarit gajienu lietotajam vajag izveleties kaulinu un nospiedit burtu <p>" << endl << " pec tam izveleties uz kuru pusi jaiet kaulinai <1> - pa kreisi <2> - pa labi" << endl;
        cout << " Damai ir iespeja ari iet atpakal <1> - pa kreisi uz leju <2> - pa labi uz leju" << endl << " <3> - pa kreisi uz augsu <4> - pa labi uz augsu" << endl;

    cout << endl;
    cout << "0 - atpakal" << endl;
    cin >> atkartot;
    }while(atkartot);
}



