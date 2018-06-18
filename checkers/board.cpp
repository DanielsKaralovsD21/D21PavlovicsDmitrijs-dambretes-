#include <iostream>
#include <windows.h>
#include "board.h"
#include "gameplay.h"
#include <string>
#include <conio.h>

using namespace std;

    int line = 8;
    int cols = 8;
    char cels[8][8];

    kaulini white;
    kaulini black;

void grafika(){

    white.puse = 'w';
    black.puse = 'b';

    system ("mode con cols=45 lines=20");

    for (int i = 0;i < line;i++){
        for (int j = 0;j < cols;j++){
            if (i <= 2 || i >= 5){
                if (i % 2 == 1){
                    if (j % 2 == 1){
                        if (i >=5 ){
                            cels[i][j] = black.puse;
                            cout << cels[i][j];
                        }else{
                        cels[i][j] = white.puse;
                        cout << cels[i][j];
                        }
                    }
                }else{
                if (i <= 2 || i >= 5){
                    if (i % 2 != 1){
                        if (j % 2 != 1){
                            if (i >=5 ){
                                cels[i][j] = black.puse;
                                cout << cels[i][j];
                            }else{
                                cels[i][j] = white.puse;
                                cout << cels[i][j];
                            }
                        }
                    }
                }
                }
            }
            cout << endl;
        }
    }
}



void change(bool atkartot, int x, int y){

    int blackskaits = 0, whiteskaits = 0;
    system ("cls");

    HANDLE a;
    COORD b;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    b.X = 20;
    b.Y = 2;
    SetConsoleCursorPosition(a,b);
    if (atkartot){
        cout << "Gajiens baltiem" << endl;
    }else
        cout << "Gajiens melniem" << endl;
    b.X = 0;
    b.Y = 0;
    SetConsoleCursorPosition(a,b);

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){

            if (cels[i][j] == black.puse || cels[i][j] == black.damka || cels[i][j] == '0')
                blackskaits++;
            if (cels[i][j] == white.puse || cels[i][j] == white.damka || cels[i][j] == '0')
                whiteskaits++;

            if (i == x && j == y){
                SetConsoleTextAttribute(a,(WORD) (8 << 4) | 15);
                cout << cels[i][j];
                SetConsoleTextAttribute(a,(WORD) (0 << 4) | 15);
                cout << "|";
            }else
                cout << cels[i][j] << "|";

        }
        cout << endl;
    }
    cout << endl;
    cout << white.vards <<": " << whiteskaits << endl;
    cout << black.vards <<": " << blackskaits << endl;

    if (blackskaits  == 0){
        system ("cls");
        cout << white.vards << " WIN!!!" << endl;
    }
    if (whiteskaits == 0){
        system ("cls");
        cout << black.vards << " WIN!!!" << endl;
    }
}

void play(){

    system ("cls");
    cout << "ievadiet vardu 1 speletajam" << endl;
    cin >> white.vards;

    cout << "ievadiet vardu 2 speletajam" << endl;
    cin >> black.vards;

    grafika();

    do{

    int  Xas, Yas, mov;

    int x = 0;
    int y = 0;
    char izvele;
    bool atkartot = true;
    white.damka = 'W';
    black.damka = 'B';

    change(atkartot,x,y);

    do{                                              // WHITE

        do{

            izvele = getch();

            if (izvele == 'w'){
                if (x > 0)
                x--;
            }

            if (izvele == 's'){
                if (x < 7)
                x++;
            }

            if (izvele == 'a'){
                if (y > 0)
                y--;
            }

            if (izvele == 'd'){
                if (y < 7)
                y++;
            }

            change(atkartot,x,y);

        }while(izvele != 'p');

        if (cels[x][y] == white.damka){                                             //WHITE DAMA

            cels[x][y] = '0';

            change(atkartot,x,y);

            cin >> mov;

            if (mov == 1){
                Xas = x + 1;
                Yas = y - 1;
                if (cels[Xas][Yas] == black.puse || cels[Xas][Yas] == black.damka){
                    if (cels[Xas+1][Yas-1] == NULL){
                        cels[x][y] = NULL;
                        cels[Xas][Yas] = NULL;
                        Xas++;
                        Yas--;
                        cels[Xas][Yas] = white.damka;
                        atkartot = false;
                    }else
                        cels[x][y] = white.damka;
                }else
                    cels[x][y] = NULL;
            }


            if (mov == 2){
                Xas = x + 1;
                Yas = y + 1;
                if (cels[Xas][Yas] == black.puse || cels[Xas][Yas] == black.damka){
                    if (cels[Xas+1][Yas+1] == NULL){
                        cels[x][y] = NULL;
                        cels[Xas][Yas] = NULL;
                        Xas++;
                        Yas++;
                        cels[Xas][Yas] = white.damka;
                        atkartot = false;
                    }else
                        cels[x][y] = white.damka;
                }else
                    cels[x][y] = NULL;
            }

            if (mov == 3){
                Xas = x - 1;
                Yas = y - 1;
                if (cels[Xas][Yas] == black.puse || cels[Xas][Yas] == black.damka){
                    if (cels[Xas-1][Yas-1] == NULL){
                        cels[x][y] = NULL;
                        cels[Xas][Yas] = NULL;
                        Xas--;
                        Yas--;
                        cels[Xas][Yas] = white.damka;
                        atkartot = false;
                    }else
                        cels[x][y] = white.damka;
                }else
                    cels[x][y] = NULL;
            }

            if (mov == 4){
                Xas = x - 1;
                Yas = y + 1;
                if (cels[Xas][Yas] == black.puse || cels[Xas][Yas] == black.damka ){
                    if (cels[Xas-1][Yas+1] == NULL){
                        cels[x][y] = NULL;
                        cels[Xas][Yas] = NULL;
                        Xas--;
                        Yas++;
                        cels[Xas][Yas] = white.damka;
                        atkartot = false;
                    }else
                        cels[x][y] = white.damka;
                }else
                    cels[x][y] = NULL;
            }

            if (cels[Xas][Yas] == NULL){
                cels[Xas][Yas] = white.damka;
                atkartot = false;
            }

        }

        change(atkartot,x,y);

        if (cels[x][y] != white.puse)
            continue;
        else{

            cels[x][y] = '0';

            change(atkartot,x,y);

            cin >> mov;

            if (mov == 1){
                Xas = x + 1;
                Yas = y - 1;
                if (cels[Xas][Yas] == black.puse || cels[Xas][Yas] == black.damka){
                    if (cels[Xas+1][Yas-1] == NULL){
                        cels[x][y] = NULL;
                        cels[Xas][Yas] = NULL;
                        Xas++;
                        Yas--;
                        cels[Xas][Yas] = white.puse;
                        atkartot = false;
                    }else
                        cels[x][y] = white.puse;
                }else
                    cels[x][y] = NULL;
            }

            if (mov == 2){
                Xas = x + 1;
                Yas = y + 1;
                if (cels[Xas][Yas] == black.puse || cels[Xas][Yas] == black.damka){
                    if (cels[Xas+1][Yas+1] == NULL){
                        cels[x][y] = NULL;
                        cels[Xas][Yas] = NULL;
                        Xas++;
                        Yas++;
                        cels[Xas][Yas] = white.puse;
                        atkartot = false;
                    }else
                        cels[x][y] = white.puse;
                }else
                    cels[x][y] = NULL;
            }



            if (cels[Xas][Yas] == NULL){
                cels[Xas][Yas] = white.puse;
                atkartot = false;
            }


            if (cels[7][Yas] == white.puse)
                cels[Xas][Yas] = white.damka;

            change(atkartot,x,y);

        }

    }while(atkartot);

    do{                                             // BLACK
        atkartot = false;

        do{

            izvele = getch();

            if (izvele == 'w'){
                if (x > 0)
                x--;
            }

            if (izvele == 's'){
                if (x < 7)
                x++;
            }

            if (izvele == 'a'){
                if (y > 0)
                y--;
            }

            if (izvele == 'd'){
                if (y < 7)
                y++;
            }

            change(atkartot,x,y);

        }while(izvele != 'p');


        if (cels[x][y] == black.damka){                                             //BLACK DAMA

            cels[x][y] = '0';

            change(atkartot,x,y);

            cin >> mov;

            if (mov == 1){
                Xas = x + 1;
                Yas = y - 1;
                if (cels[Xas][Yas] == white.puse || cels[Xas][Yas] == white.damka){
                    if (cels[Xas+1][Yas-1] == NULL){
                        cels[x][y] = NULL;
                        cels[Xas][Yas] = NULL;
                        Xas++;
                        Yas--;
                        cels[Xas][Yas] = black.damka;
                        atkartot = true;
                    }else
                        cels[x][y] = black.damka;
                }else
                    cels[x][y] = NULL;
            }


            if (mov == 2){
                Xas = x + 1;
                Yas = y + 1;
                if (cels[Xas][Yas] == white.puse || cels[Xas][Yas] == white.damka){
                    if (cels[Xas+1][Yas+1] == NULL){
                        cels[x][y] = NULL;
                        cels[Xas][Yas] = NULL;
                        Xas++;
                        Yas++;
                        cels[Xas][Yas] = black.damka;
                        atkartot = true;
                    }else
                        cels[x][y] = black.damka;
                }else
                    cels[x][y] = NULL;
            }

            if (mov == 3){
                Xas = x - 1;
                Yas = y - 1;
                if (cels[Xas][Yas] == white.puse || cels[Xas][Yas] == white.damka){
                        if (cels[Xas-1][Yas-1] == NULL){
                        cels[x][y] = NULL;
                        cels[Xas][Yas] = NULL;
                        Xas--;
                        Yas--;
                        cels[Xas][Yas] = black.damka;
                        atkartot = true;
                    }else
                        cels[x][y] = black.damka;
                }else
                    cels[x][y] = NULL;
            }

            if (mov == 4){
                Xas = x - 1;
                Yas = y + 1;
                if (cels[Xas][Yas] == white.puse || cels[Xas][Yas] == white.damka){
                    if (cels[Xas-1][Yas+1] == NULL){
                        cels[x][y] = NULL;
                        cels[Xas][Yas] = NULL;
                        Xas--;
                        Yas++;
                        cels[Xas][Yas] = black.damka;
                        atkartot = true;
                    }else
                        cels[x][y] = black.damka;
                }else
                    cels[x][y] = NULL;
            }

            if (cels[Xas][Yas] == NULL){
                cels[Xas][Yas] = black.damka;
                atkartot = true;
            }

        }
        change(atkartot,x,y);

    if (cels[x][y] != black.puse){
        continue;
    }else
        cels[x][y] = '0';

    change(atkartot,x,y);

    cin >> mov;

    if (mov == 1){
        Xas = x - 1;
        Yas = y - 1;
        if (cels[Xas][Yas] == white.puse || cels[Xas][Yas] == white.damka){
            if (cels[Xas-1][Yas-1] == NULL){
                cels[x][y] = NULL;
                cels[Xas][Yas] = NULL;
                Xas--;
                Yas--;
                cels[Xas][Yas] = black.puse;
                atkartot = true;
            }else
                cels[x][y] = black.puse;
        }else
            cels[x][y] = NULL;
    }

    if (mov == 2){
        Xas = x - 1;
        Yas = y + 1;
         if (cels[Xas][Yas] == white.puse || cels[Xas][Yas] == white.damka){
            if (cels[Xas-1][Yas+1] == NULL){
                cels[x][y] = NULL;
                cels[Xas][Yas] = NULL;
                Xas--;
                Yas++;
                cels[Xas][Yas] = black.puse;
                atkartot = true;
            }else
                cels[x][y] = black.puse;
         }else
            cels[x][y] = NULL;
    }

    if (cels[Xas][Yas] == NULL){
        cels[Xas][Yas] = black.puse;
        atkartot = true;
    }

    if (cels[0][Yas] == black.puse)
        cels[Xas][Yas] = black.damka;

    change(atkartot,x,y);

    }while(!atkartot);

    }while(true);
}









