#include <iostream>
#include <windows.h>
#include "menu.h"
#include "gameplay.h"
#include "board.h"

using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");

    int izvele;
    int atkartot = 1;

    do
    {

    system("cls");
    menu();

    cin  >> izvele;
    if (izvele == 1){ play();
    }else
    if (izvele == 2){ tutorial();
    }else
    if (izvele == 0) atkartot = 0;
    }while(atkartot);


return 0;
}
