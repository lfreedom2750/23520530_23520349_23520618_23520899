#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;
# 123456
void gotoxy (int column, int line);

struct Point
{
    int x,y;
};

class ConRan
{
    public:
        Point A[100];
        int DoDai;

        ConRan()
        {
            DoDai = 3;
            A[0].x = 10; A[0].y = 10;
            A[1].x = 11; A[1].y = 10;
            A[2].x = 12; A[2].y = 10;
        }

        void Ve()
        {
            for (int i = 0; i < DoDai; i++)
            {
                gotoxy(A[i].x,A[i].y);
                cout << "XX";
            }
        }

        void DiChuyen(int Huong)
        {
            for (int i = DoDai - 1; i > 0; i--)
                A[i] = A[i - 1];
            if (Huong == 0) A[0].y = A[0].y - 1; // len tren
            if (Huong == 1) A[0].x = A[0].x - 1; // qua trai
            if (Huong == 2) A[0].y = A[0].y + 1; // xuong duoi
            if (Huong == 3) A[0].x = A[0].x + 1; // qua phai
        }
};

int main()
{
    ConRan r;
    int Huong = 3;
    char t;

    while (1)
    {
        if (kbhit())
        {
            t = getch();
            if (t == 'w') Huong = 0;
            if (t == 'a') Huong = 1;
            if (t == 's') Huong = 2;
            if (t == 'd') Huong = 3;
        }

        system("cls");
        r.Ve();
        r.DiChuyen(Huong);
        Sleep(200);
    }

    return 0;
}


void gotoxy (int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord);
}
