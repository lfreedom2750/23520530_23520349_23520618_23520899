#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <cmath>
using namespace std;

//placeholders REMOVE AFTER MERGE AND REPLACE WITH REAL VARIABLES
//lines with variables that need to be replaced is marked with "//"
vector <pair < int , int >> temp_snake; 
int snake_length = 3;
void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }
int player_score=0;
//end of placeholders

class Food
{
    private:
    pair< int , int > coordinate;
    public:
    int state = 1; // 1->normal, 0->eaten, set this to eaten when snake head have same coordinate as food || run CheckEaten each draw cycle
    void Draw()
    {
        gotoxy( coordinate.first, coordinate.second );
        printf ("O");
    }
    Food()
    {
        Spawn();
    }
    void Spawn()
    {
        srand(unsigned(time)); //replace time with snake head line or column value
        int occupied = 0;
        
        while (occupied == 0)
        {
            pair< int , int > prev = coordinate;
            coordinate = { rand() % 640, rand() % 480}; //replace with game resolution
            for (int i=0; i < snake_length; i++)//
            {
                if (temp_snake[i] == coordinate || coordinate == prev )//
                {
                    occupied = 1;
                    break;
                }
            }
        }
        Draw();
    }
    
    void CheckEaten()
    {
        if (state == 0)
        {
            player_score++;//
            snake_length++;//
            Spawn();
        }
    }
};