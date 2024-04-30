#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <cmath>
#define MINX 5
#define MINY 5
#define MAXX 40
#define MAXY 30
using namespace std;

void gotoxy(int column, int line);

struct Point
{
    int x,y;
};

class Snake
{
    public:
        Point points[100];
        int length;
        Snake()
        {
            length = 3;
            points[0].x = 10; points[0].y = 10;
            points[1].x = 11; points[1].y = 10;
            points[2].x = 12; points[2].y = 10;
        }

        void Draw()
        {
            for (int i = 0; i < length; i++){
                gotoxy(points[i].x,points[i].y);
                cout<<"$";
            }

            
        }

        void Move(int dir)
        {   
            for (int i = length - 1; i > 0; i--)
                points[i] = points[i - 1];

            if (dir == 0) points[0].y -= 1; // di len
            if (dir == 1) points[0].x -= 1; // sang trai
            if (dir == 2) points[0].y += 1; // di xuong
            if (dir == 3) points[0].x += 1; // sang phai
        }
};

int main()
{
    Snake r;
    int dir = 3, old_dir;
    char t;
    bool check = 0;

    while (!check)
    {
        if (kbhit())
        {
            old_dir = dir;
            t = getch();
            if (t=='w') dir = 0;
            if (t=='a') dir = 1;
            if (t=='s') dir = 2;
            if (t=='d') dir = 3;
            if (t == 13)
                check = 1;
            if (abs(dir - old_dir) == 2)
                dir = old_dir;
        }
        system("cls");
        r.Draw();
        r.Move(dir);
        Sleep(250);
    }

    return 0;
}


void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
