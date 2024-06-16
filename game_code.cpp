#include <iostream>
#include "mygraphics.h"
#include "myconsole.h"
#include<fstream>
#include<string>
#include<sstream>
#include<conio.h>

using namespace std;

int main()
{
    int size;
    bool display = false;   //BULLET KAI TRUE FALSE KAI LIYE
    int up = 0;                //INITIALIZATION
    int win_x = 0, win_y = 0;    //GRID DIMENSIONS
    int box_x, box_y;            //BOX KA X AUR Y
    int ball_x, ball_y;          //SPACESHIP KA X AUR Y
    bool dir = false;
    bool flag = true;           // WHILE KA TRUE AUR FALSE
    char demo[] = "score";
    char space[] = "lives";
    bool pressed = false;
    int shipup = 0;
    int shiplr = 0;
    int bulletup = 0;
    int bulletlr = 0;
    int score = 0;
    int lives = 3;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0, a10 = 0;       // LINE 1 KAI LIYE HAI UPER BOX KO BHEJNE KAI LIYE
    int b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0, b7 = 0, b8 = 0, b9 = 0, b10 = 0;   //LINE2
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0, c10 = 0;   // LINE3
    int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0, d8 = 0, d9 = 0, d10 = 0;   //LINE4
    int e1 = 0, e2 = 0, e3 = 0, e4 = 0, e5 = 0, e6 = 0, e7 = 0, e8 = 0, e9 = 0, e10 = 0;   //LINE5
    int col[50] = { 0 };  //COLLISION KO 1 DAFA KRANAY KAI LIYE
    int arrsc[5] = { 0 };
    int i = 0;
    int check = 0;
    int black[100] = { 0 };
    bool life = true;
    int l1 = 0, l2 = 0, l3 = 0, l4 = 0, l5 = 0;

    fstream myfile;
    fstream save;


    //system("pause");
    GetWindowDimensions(win_x, win_y);   //FUNCTION CALL
    SetWindowTitle(demo);                //FUNCTION CALL
    box_x = 0;
    box_y = 0;
    ball_x = win_x / 2;   //ball ka x axis
    ball_y = win_y - 50;  //ball ka y axiS

    save.open("savegame.txt", ios::in);
    {
        if (save.is_open()) {
            save >> score; save << endl; save >> lives; save << endl; save >> ball_x; save << endl; save >> ball_y; save << endl;
            save >> a1; save << endl; save >> a2; save << endl; save >> a3; save << endl; save >> a4;
            save << endl; save >> a5; save << endl; save >> a6; save << endl; save >> a7; save << endl; save >> a8;
            save << endl; save >> a9; save << endl; save >> a10; save << endl; save >> b1; save << endl; save >> b2; save << endl; save >> b3; save << endl; save >> b4;
            save << endl; save >> b5; save << endl; save >> b6; save << endl; save >> b7; save << endl; save >> b8;
            save << endl; save >> b9; save << endl; save >> b10; save << endl; save >> c1; save << endl; save >> c2; save << endl; save >> c3; save << endl; save >> c4;
            save << endl; save >> c5; save << endl; save >> c6; save << endl; save >> c7; save << endl; save >> c8;
            save << endl; save >> c9; save << endl; save >> c10; save << endl; save >> d1; save << endl; save >> d2; save << endl; save >> d3; save << endl; save >> d4;
            save << endl; save >> d5; save << endl; save >> d6; save << endl; save >> d7; save << endl; save >> d8;
            save << endl; save >> d9; save << endl; save >> d10; save << endl; save >> e1; save << endl; save >> e2; save << endl; save >> e3; save << endl; save >> e4;
            save << endl; save >> e5; save << endl; save >> e6; save << endl; save >> e7; save << endl; save >> e8;
            save << endl; save >> e9; save << endl; save >> e10; save << endl; save >> box_x; save << endl; save >> box_y;
            save << endl; save >> win_x; save << endl; save >> win_y;
        }
    }
    save.close();

    while (flag) {
        //GAME LOOP
        cout << "   " << score;//SCORE PRINT KR RHA
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t     " << lives;
        PlaceCursor(0, 0);
        myDrawTextWithFont(win_x - 950, win_y / 45, 20, demo, RGB(0, 255, 0), RGB(20, 20, 20));//SCORE YE LIKH RHA HAI
        myDrawTextWithFont(win_x - 100, win_y / 45, 20, space, RGB(0, 255, 0), RGB(20, 20, 20)); //LIVES LIKHTA
      //BOX MOVEMENT
        box_y += 1 - dir * 50;
        if (box_y <= 0)
            dir = !dir;

        if (score == 500) {//JB SARAY ALIENS KHATAM TOU YE CHALE GA 
            cout << "          YOU WON";
            break;
        }





        int a = CheckKeyPressed();

        if (a == LEFTKEY && ball_x > 0)
            ball_x -= 20;
        else if (a == RIGHTKEY && ball_x < (win_x - 50))
            ball_x += 20;
        // AGR GAME PAUSE KRNI HAI USS KAI LIYE HAI YE
        else if (a == 32)
            display = true;


        else if (a == DOWNKEY && ball_y < win_y - 50)

            ball_y += 50;
        else if (a == UPKEY && ball_y > 50)
            ball_y -= 50;
        /*if (a == 27) {
            cout << "you paused the game";
            system("pause");
        }*/

        Sleep(10);
        //NEEECHAY LINE PE LAGAY GA TOU GAME OVER 
       if (box_y + a1 > win_y && col[0] == 0) { ClearScreen(); break; }
        else  if (box_y + a2 > win_y && col[1] == 0) { ClearScreen(); break; }
        else if (box_y + a3 > win_y && col[2] == 0) { ClearScreen(); break; }
        else if (box_y + a4 > win_y && col[3] == 0) { ClearScreen(); break; }
        else if (box_y + a5 > win_y && col[4] == 0) { ClearScreen(); break; }
       /*  else if (box_y + a6 > win_y && col[5] == 0) { ClearScreen(); break; }
        else if (box_y + a7 > win_y && col[6] == 0) { ClearScreen(); break; }
        else if (box_y + a8 > win_y && col[7] == 0) { ClearScreen(); break; }
        else if (box_y + a9 > win_y && col[8] == 0) { ClearScreen(); break; }
        else if (box_y + a10 > win_y && col[9] == 0) { ClearScreen(); break; }
        else if (box_y + +b1 > win_y && col[10] == 0) { ClearScreen(); break; }
        else if (box_y + b2 > win_y && col[11] == 0) { ClearScreen(); break; }
        else if (box_y + b3 > win_y && col[12] == 0) { ClearScreen(); break; }
        else if (box_y + b4 > win_y && col[13] == 0) { ClearScreen(); break; }
        else if (box_y + b5 > win_y && col[14] == 0) { ClearScreen(); break; }
        else if (box_y + b6 > win_y && col[15] == 0) { ClearScreen(); break; }
        else if (box_y + b7 > win_y && col[16] == 0) { ClearScreen(); break; }
        else if (box_y + b8 > win_y && col[17] == 0) { ClearScreen(); break; }
        else if (box_y + b9 > win_y && col[18] == 0) { ClearScreen(); break; }
        else if (box_y + b10 > win_y && col[19] == 0) { ClearScreen(); break; }
        else if (box_y + c1 > win_y && col[20] == 0) { ClearScreen(); break; }
        else if (box_y + c2 > win_y && col[21] == 0) { ClearScreen(); break; }
        else if (box_y + c3 > win_y && col[22] == 0) { ClearScreen(); break; }
        else if (box_y + c4 > win_y && col[23] == 0) { ClearScreen(); break; }
        else if (box_y + c5 > win_y && col[24] == 0) { ClearScreen(); break; }
        else if (box_y + c6 > win_y && col[25] == 0) { ClearScreen(); break; }
        else if (box_y + c7 > win_y && col[26] == 0) { ClearScreen(); break; }
        else if (box_y + c8 > win_y && col[27] == 0) { ClearScreen(); break; }
        else if (box_y + c9 > win_y && col[28] == 0) { ClearScreen(); break; }
        else if (box_y + c10 > win_y && col[29] == 0) { ClearScreen(); break; }
        else if (box_y + d1 > win_y && col[30] == 0) { ClearScreen(); break; }
        else if (box_y + d2 > win_y && col[31] == 0) { ClearScreen(); break; }
        else if (box_y + d3 > win_y && col[32] == 0) { ClearScreen(); break; }
        else if (box_y + d4 > win_y && col[33] == 0) { ClearScreen(); break; }
        else if (box_y + d5 > win_y && col[34] == 0) { ClearScreen(); break; }
        else if (box_y + d6 > win_y && col[35] == 0) { ClearScreen(); break; }
        else if (box_y + d7 > win_y && col[36] == 0) { ClearScreen(); break; }
        else if (box_y + d8 > win_y && col[37] == 0) { ClearScreen(); break; }
        else if (box_y + d9 > win_y && col[38] == 0) { ClearScreen(); break; }
        else if (box_y + d10 > win_y && col[39] == 0) { ClearScreen(); break; }
        else if (box_y + e1 > win_y && col[40] == 0) { ClearScreen(); break; }
        else if (box_y + e2 > win_y && col[41] == 0) { ClearScreen(); break; }
        else if (box_y + e3 > win_y && col[42] == 0) { ClearScreen(); break; }
        else if (box_y + e4 > win_y && col[43] == 0) { ClearScreen(); break; }
        else if (box_y + e5 > win_y && col[44] == 0) { ClearScreen(); break; }
        else if (box_y + e6 > win_y && col[45] == 0) { ClearScreen(); break; }
        else if (box_y + e7 > win_y && col[46] == 0) { ClearScreen(); break; }
        else if (box_y + e8 > win_y && col[47] == 0) { ClearScreen(); break; }
        else if (box_y + e9 > win_y && col[48] == 0) { ClearScreen(); break; }
        else if (box_y + e10 > win_y && col[49] == 0) { ClearScreen(); break; }*/

        //CLEAR PREVIOUS FRAME
        ClearScreen();

        //RENDER NEW FRAME
        myLine(0, win_y, win_x, win_y, RGB(255, 255, 0));
        //subtracting 20 to maintain space and size.
        //LINE ONE OF ALIENS
        if (black[0] == 0) myRect(box_x, box_y + a1, box_x + 30, box_y + 30 + a1, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[1] == 0) myRect(box_x + 90, box_y + a2, box_x + 120, box_y + 30 + a2, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[2] == 0) myRect(box_x + 180, box_y + a3, box_x + 210, box_y + 30 + a3, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[3] == 0)myRect(box_x + 270, box_y + a4, box_x + 300, box_y + 30 + a4, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[4] == 0)myRect(box_x + 360, box_y + a5, box_x + 390, box_y + 30 + a5, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[5] == 0)myRect(box_x + 450, box_y + a6, box_x + 480, box_y + 30 + a6, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[6] == 0)myRect(box_x + 540, box_y + a7, box_x + 570, box_y + 30 + a7, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[7] == 0) myRect(box_x + 630, box_y + a8, box_x + 660, box_y + 30 + a8, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[8] == 0)myRect(box_x + 720, box_y + a9, box_x + 750, box_y + 30 + a9, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[9] == 0) myRect(box_x + 810, box_y + a10, box_x + 840, box_y + 30 + a10, RGB(255, 0, 0), RGB(255, 0, 0));
        //LINE TWO OF ALIENS

        if (black[10] == 0)myRect(box_x, box_y - 60 + b1, box_x + 30, box_y - 30 + b1, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[12] == 0) myRect(box_x + 90, box_y - 60 + b2, box_x + 120, box_y - 30 + b2, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[13] == 0)myRect(box_x + 180, box_y - 60 + b3, box_x + 210, box_y - 30 + b3, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[14] == 0) myRect(box_x + 270, box_y - 60 + b4, box_x + 300, box_y - 30 + b4, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[15] == 0)myRect(box_x + 360, box_y - 60 + b5, box_x + 390, box_y - 30 + b5, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[16] == 0)myRect(box_x + 450, box_y - 60 + b6, box_x + 480, box_y - 30 + b6, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[17] == 0)myRect(box_x + 540, box_y - 60 + b7, box_x + 570, box_y - 30 + b7, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[18] == 0)myRect(box_x + 630, box_y - 60 + b8, box_x + 660, box_y - 30 + b8, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[19] == 0)myRect(box_x + 720, box_y - 60 + b9, box_x + 750, box_y - 30 + b9, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[20] == 0)myRect(box_x + 810, box_y - 60 + b10, box_x + 840, box_y - 30 + b10, RGB(255, 0, 0), RGB(255, 0, 0));

        // LINE THREE OF ALIENS   
        if (black[21] == 0)myRect(box_x, box_y - 120 + c1, box_x + 30, box_y - 90 + c1, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[22] == 0)myRect(box_x + 90, box_y - 120 + c2, box_x + 120, box_y - 90 + c2, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[23] == 0)myRect(box_x + 180, box_y - 120 + c3, box_x + 210, box_y - 90 + c3, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[24] == 0)myRect(box_x + 270, box_y - 120 + c4, box_x + 300, box_y - 90 + c4, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[25] == 0)myRect(box_x + 360, box_y - 120 + c5, box_x + 390, box_y - 90 + c5, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[26] == 0)myRect(box_x + 450, box_y - 120 + c6, box_x + 480, box_y - 90 + c6, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[27] == 0)myRect(box_x + 540, box_y - 120 + c7, box_x + 570, box_y - 90 + c7, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[28] == 0)myRect(box_x + 630, box_y - 120 + c8, box_x + 660, box_y - 90 + c8, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[29] == 0)myRect(box_x + 720, box_y - 120 + c9, box_x + 750, box_y - 90 + c9, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[30] == 0)myRect(box_x + 810, box_y - 120 + c10, box_x + 840, box_y - 90 + c10, RGB(255, 0, 0), RGB(255, 0, 0));
        // LINE FOUR OF ALIENS
        if (black[31] == 0)myRect(box_x, box_y - 180 + d1, box_x + 30, box_y - 150 + d1, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[32] == 0)myRect(box_x + 90, box_y - 180 + d2, box_x + 120, box_y - 150 + d2, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[33] == 0)myRect(box_x + 180, box_y - 180 + d3, box_x + 210, box_y - 150 + d3, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[34] == 0)myRect(box_x + 270, box_y - 180 + d4, box_x + 300, box_y - 150 + d4, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[35] == 0)myRect(box_x + 360, box_y - 180 + d5, box_x + 390, box_y - 150 + d5, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[36] == 0)myRect(box_x + 450, box_y - 180 + d6, box_x + 480, box_y - 150 + d6, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[37] == 0)myRect(box_x + 540, box_y - 180 + d7, box_x + 570, box_y - 150 + d7, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[38] == 0)myRect(box_x + 630, box_y - 180 + d8, box_x + 660, box_y - 150 + d8, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[39] == 0)myRect(box_x + 720, box_y - 180 + d9, box_x + 750, box_y - 150 + d9, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[40] == 0)myRect(box_x + 810, box_y - 180 + d10, box_x + 840, box_y - 150 + d10, RGB(255, 0, 0), RGB(255, 0, 0));
        // LINE FIVE OF ALIENS
        if (black[41] == 0)myRect(box_x, box_y - 240 + e1, box_x + 30, box_y - 210 + e1, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[42] == 0)myRect(box_x + 90, box_y - 240 + e2, box_x + 120, box_y - 210 + e2, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[43] == 0)myRect(box_x + 180, box_y - 240 + e3, box_x + 210, box_y - 210 + e3, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[44] == 0)myRect(box_x + 270, box_y - 240 + e4, box_x + 300, box_y - 210 + e4, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[45] == 0)myRect(box_x + 360, box_y - 240 + e5, box_x + 390, box_y - 210 + e5, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[46] == 0)myRect(box_x + 450, box_y - 240 + e6, box_x + 480, box_y - 210 + e6, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[47] == 0)myRect(box_x + 540, box_y - 240 + e7, box_x + 570, box_y - 210 + e7, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[48] == 0)myRect(box_x + 630, box_y - 240 + e8, box_x + 660, box_y - 210 + e8, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[49] == 0)myRect(box_x + 720, box_y - 240 + e9, box_x + 750, box_y - 210 + e9, RGB(255, 0, 0), RGB(255, 0, 0));
        if (black[50] == 0)myRect(box_x + 810, box_y - 240 + e10, box_x + 840, box_y - 210 + e10, RGB(255, 0, 0), RGB(255, 0, 0));


        mySetPixel(win_x / 2, win_y / 2 + 100, RGB(0, 255, 0));
        myEllipse(ball_x + shiplr, ball_y + shipup, ball_x + 50 + shiplr, ball_y + 50 + shipup, RGB(0, 255, 255), RGB(0, 255, 255));//ball ka size

        if (display == true) {
            static int bulletlr = shiplr;
            static int bulletup = shipup;
            myRect(ball_x + 21 + bulletlr, ball_y - 15 - up + bulletup, ball_x + 32 + bulletlr, ball_y - up + bulletup, RGB(0, 255, 255), RGB(0, 255, 255));
            up += 50;
            //BULLET UPER JA RHI HAI AUR BULLET KI CONDITION
            if (box_y >= ball_y - 15 - up || box_y + 30 == ball_y - up) {       //FIRST LINE KAI Y AXIS KI LIMIT  BULLET YE DEKHE GI
                if (ball_x - 20 <= box_x && ball_x <= box_x && col[0] == 0) {      //LINE 1 KAI BOX 1 KI CONDITION 
                    a1 -= 5000000; score += 10; up = 0; col[0] = 1; display = false;  // A1 UPER BHEJ RHA  SCORE 10PLUS HO RHA  UP=0 BULLET KO BREAK KR RHA  DISPLAY =FALSE
                }
                else if (ball_x + 20 >= box_x + 90 && ball_x <= box_x + 120 && col[1] == 0) {
                    a2 -= 50000000; score += 10; up = 0; col[1] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 180 && ball_x <= box_x + 210 && col[2] == 0) {
                    a3 -= 5000000; score += 10; up = 0; col[2] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 270 && ball_x <= box_x + 300 && col[3] == 0) {
                    a4 -= 500000; score += 10; up = 0; col[3] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 360 && ball_x <= box_x + 390 && col[4] == 0) {
                    a5 -= 500000; score += 10; up = 0; col[4] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 450 && ball_x <= box_x + 480 && col[5] == 0) {
                    a6 -= 5000000; score += 10; up = 0; col[5] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 540 && ball_x <= box_x + 570 && col[6] == 0) {
                    a7 -= 500000; score += 10; up = 0; col[6] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 630 && ball_x <= box_x + 660 && col[7] == 0) {
                    a8 -= 5000000; score += 10; up = 0; col[7] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 720 && ball_x <= box_x + 750 && col[8] == 0) {
                    a9 -= 5000000; score += 10; up = 0;  col[8] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 810 && ball_x <= box_x + 840 && col[9] == 0) {
                    a10 -= 5000000; score += 10; up = 0; col[9] = 1; display = false;
                }
            }
            if (box_y - 60 >= ball_y - 15 - up || box_y - 30 == ball_y - up - 30) {//SECOND LINE KAI Y AXIS KI LIMIT  BULLET YE DEKHE GI
                if (ball_x - 20 <= box_x && ball_x <= box_x + 30 && col[10] == 0) {
                    b1 -= 5000000; score += 10; up = 0; col[10] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 90 && ball_x <= box_x + 120 && col[11] == 0) {
                    b2 -= 5000; score += 10; up = 0; col[11] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 180 && ball_x <= box_x + 210 && col[12] == 0) {
                    b3 -= 5000000; score += 10; up = 0; col[12] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 270 && ball_x <= box_x + 300 && col[13] == 0) {
                    b4 -= 5000000; score += 10; up = 0; col[13] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 360 && ball_x <= box_x + 390 && col[14] == 0) {
                    b5 -= 5000000; score += 10; up = 0; col[14] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 450 && ball_x <= box_x + 480 && col[15] == 0) {
                    b6 -= 5000000; score += 10; up = 0; col[15] = 1;  display = false;
                }
                else if (ball_x + 20 >= box_x + 540 && ball_x <= box_x + 570 && col[16] == 0) {
                    b7 -= 5000000; score += 10; up = 0; col[16] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 630 && ball_x <= box_x + 660 && col[17] == 0) {
                    b8 -= 5000000; score += 10; up = 0; col[17] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 720 && ball_x <= box_x + 750 && col[18] == 0) {
                    b9 -= 5000000; score += 10; up = 0; col[18] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 810 && ball_x <= box_x + 840 && col[19] == 0) {
                    b10 -= 5000000; score += 10;  up = 0; col[19] = 1; display = false;
                }
            }
            if (box_y - 120 >= ball_y - 15 - up || box_y - 90 == ball_y - up - 30) { ///THIRD LINE KAI Y AXIS KI LIMIT  BULLET YE DEKHE GI
                if (ball_x - 20 <= box_x && ball_x <= box_x + 30 && col[20] == 0) {
                    c1 -= 5000000; score += 10; up = 0; col[20] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 90 && ball_x <= box_x + 120 && col[21] == 0) {
                    c2 -= 5000000; score += 10; up = 0; col[21] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 180 && ball_x <= box_x + 210 && col[22] == 0) {
                    c3 -= 5000000; score += 10; up = 0; col[22] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 270 && ball_x <= box_x + 300 && col[23] == 0) {
                    c4 -= 5000000; score += 10; up = 0; col[23] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 360 && ball_x <= box_x + 390 && col[24] == 0) {
                    c5 -= 5000000; score += 10; up = 0; col[24] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 450 && ball_x <= box_x + 480 && col[25] == 0) {
                    c6 -= 5000000; score += 10; up = 0; col[25] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 540 && ball_x <= box_x + 570 && col[26] == 0) {
                    c7 -= 5000000; score += 10; up = 0; col[26] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 630 && ball_x <= box_x + 660 && col[27] == 0) {
                    c8 -= 5000000; score += 10; up = 0; col[27] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 720 && ball_x <= box_x + 750 && col[28] == 0) {
                    c9 -= 5000000; score += 10; up = 0; col[28] = 1; display = false;
                }
                else if (ball_x + 20 >= box_x + 810 && ball_x <= box_x + 840 && col[29] == 0) {
                    c10 -= 5000000; score += 10; up = 0; col[29] = 1; display = false;
                }
            }


        }
        if (box_y - 180 >= ball_y - 15 - up || box_y - 150 == ball_y - up - 30) { //FOURTH LINE KAI Y AXIS KI LIMIT  BULLET YE DEKHE GI
            if (ball_x - 20 <= box_x && ball_x <= box_x + 30 && col[30] == 0) {
                d1 -= 5000000; score += 10; up = 0; col[30] = 1; display = false;
            }
            else if (ball_x + 20 >= box_x + 90 && ball_x <= box_x + 120 && col[31] == 0) {
                d2 -= 5000000; score += 10; up = 0; col[31] = 1; display = false;
            }
            else if (ball_x + 20 >= box_x + 180 && ball_x <= box_x + 210 && col[32] == 0) {
                d3 -= 5000000; score += 10; up = 0; col[32] = 1; display = false;
            }
            else if (ball_x + 20 >= box_x + 270 && ball_x <= box_x + 300 && col[33] == 0) {
                d4 -= 5000000; score += 10; up = 0; col[33] = 1; display = false;
            }
            else if (ball_x + 20 >= box_x + 360 && ball_x <= box_x + 390 && col[34] == 0) {
                d5 -= 500000; score += 10; up = 0; col[34] = 1; display = false;
            }
            else if (ball_x + 20 >= box_x + 450 && ball_x <= box_x + 480 && col[35] == 0) {
                d6 -= 5000000; score += 10; up = 0; col[35] = 1; display = false;
            }
            else if (ball_x + 20 >= box_x + 540 && ball_x <= box_x + 570 && col[36] == 0) {
                d7 -= 5000000; score += 10; up = 0; col[36] = 1; display = false;
            }
            else if (ball_x + 20 >= box_x + 630 && ball_x <= box_x + 660 && col[37] == 0) {
                d8 -= 5000000; score += 10; up = 0; col[37] = 1; display = false;
            }
            else if (ball_x + 20 >= box_x + 720 && ball_x <= box_x + 750 && col[38] == 0) {
                d9 -= 500000; score += 10; up = 0; col[38] = 1; display = false;
            }
            else if (ball_x + 20 >= box_x + 810 && ball_x <= box_x + 840 && col[39] == 0) {
                d10 -= 5000000; score += 10; up = 0; col[39] = 1; display = false;
            }

        }
        if (box_y - 240 >= ball_y - 15 - up || box_y - 210 == ball_y - up - 30) { //FIFTH LINE KAI Y AXIS KI LIMIT  BULLET YE DEKHE GI
            if (ball_x - 20 <= box_x && ball_x <= box_x + 30 && col[40] == 0) {
                e1 -= 5000000; score += 10; up = 0; col[40] = 1; display = false;
            }
            else if (ball_x + 20 >= box_x + 90 && ball_x <= box_x + 120 && col[41] == 0) {
                e2 -= 5000000; score += 10; up = 0; col[41] = 1; display = false;
            }
            else if (ball_x + 20 >= box_x + 180 && ball_x <= box_x + 210 && col[42] == 0) {
                e3 -= 5000000; score += 10; up = 0; col[42] = 1; display = false;
            }
            else if (ball_x + 20 >= box_x + 270 && ball_x <= box_x + 300 && col[43] == 0) {
                e4 -= 5000000; score += 10; up = 0; col[43] = 1; display = false;
            }
            else if (ball_x + 20 >= box_x + 360 && ball_x <= box_x + 390 && col[44] == 0) {
                e5 -= 5000000; score += 10; up = 0; col[44] = 1; display = false;
            }
            else if (ball_x + 20 >= box_x + 450 && ball_x <= box_x + 480 && col[45] == 0) {
                e6 -= 5000000; score += 10; up = 0; col[45] = 1; display = false;
            }
            else if (ball_x + 20 >= box_x + 540 && ball_x <= box_x + 570 && col[46] == 0) {
                e7 -= 5000000; score += 10; up = 0; col[46] = 1; display = false;
            }
            else if (ball_x + 20 >= box_x + 630 && ball_x <= box_x + 660 && col[47] == 0) {
                e8 -= 5000000; score += 10; up = 0; col[47] = 1; display = false;
            }
            else if (ball_x + 20 >= box_x + 720 && ball_x <= box_x + 750 && col[48] == 0) {
                e9 -= 5000000; score += 10; up = 0; col[48] = 1; display = false;
            }
            else if (ball_x + 20 >= box_x + 810 && ball_x <= box_x + 840 && col[49] == 0) {
                e10 -= 5000000; score += 10; up = 0; col[49] = 1; display = false;
            }


        }

        if (ball_y - 15 - up + bulletup < 0 && a == 32) {    // BULLET KHATAM HOTI JB TOP Y AXIS PR LGTI
            display == false;
            up = 0;
            bulletlr = shiplr;
            bulletup = shipup;
        }

       if (box_y >= ball_y - 15 - up || box_y + 30 == ball_y - up == ball_y) {
            if (l1 == 0) {
                lives--;
                l1 = 1;
            }
  }

        if (box_y -60>= ball_y - 15 - up || box_y + 30 == ball_y - up-30 == ball_y) {
            if (l2 == 0) {
                lives--;
                l2 = 1;
            }
        }
        if (box_y - 120 >= ball_y - 15 - up || box_y + 30 == ball_y - up - 30 == ball_y) {
            if (l3 == 0) {
                lives--;
                l3 = 1;
            }
        }


      //  if (lives == 0) {
     //       break;
      //  }
        
        check = score;
        if (a == 27) {
            save.open("savegame.txt", ios::out);
            {
                if (save.is_open()) {
                    save << score; save << endl; save << lives; save << endl; save << ball_x; save << endl; save << ball_y; save << endl;
                    save << a1; save << endl; save << a2; save << endl; save << a3; save << endl; save << a4;
                    save << endl; save << a5; save << endl; save << a6; save << endl; save << a7; save << endl; save << a8;
                    save << endl; save << a9; save << endl; save << a10; save << b1; save << endl; save << b2; save << endl; save << b3; save << endl; save << b4;
                    save << endl; save << b5; save << endl; save << b6; save << endl; save << b7; save << endl; save << b8;
                    save << endl; save << b9; save << endl; save << b10; save << c1; save << endl; save << c2; save << endl; save << c3; save << endl; save << c4;
                    save << endl; save << c5; save << endl; save << c6; save << endl; save << c7; save << endl; save << c8;
                    save << endl; save << c9; save << endl; save << c10; save << d1; save << endl; save << d2; save << endl; save << d3; save << endl; save << d4;
                    save << endl; save << d5; save << endl; save << d6; save << endl; save << d7; save << endl; save << d8;
                    save << endl; save << d9; save << endl; save << d10; save << e1; save << endl; save << e2; save << endl; save << e3; save << endl; save << e4;
                    save << endl; save << e5; save << endl; save << e6; save << endl; save << e7; save << endl; save << e8;
                    save << endl; save << e9; save << endl; save << e10; save << endl; save << box_x; save << endl; save << box_y;
                    save << endl; save << win_x; save << endl; save << win_y;
                }
                            
                              break;
            }save.close();
        }
    }


  
        
        





    myfile.open("highscores.txt", ios::out | ios::app);   //HIGH SCORE KI FILE BNAI HAI
    {
        if (myfile.is_open()) {    //OPEN KI HAI FILE AUR CHECK KR RHE KAI OPEN HUI 
            myfile << score;           //SCORE SAVE KRWA RHE
            myfile << endl;

        }
        myfile.close();          //FILE BND KR RHE

    }

    string line;
    myfile.open("highscores.txt", ios::in);  //FILE KO READ KR RHE
    {
        if (myfile.is_open()) {
            cout << "ALL HIGH SCORES ARE";
            while (getline(myfile, line)) {         //LINE BY LINE STRING READ KR RHE HIGHSCOREFILE SAY
                istringstream(line) >> arrsc[i];//STRING KO INTEGER MAI CONVERT KR KAI USS KO ARRSC MAI STORE KRA RHE
                cout << endl;
                cout << arrsc[i];//SCORE KO DISPLAY KRWA RHE
                cout << endl;
                i++;
            }
            myfile.close();





        }


    }

    

}
