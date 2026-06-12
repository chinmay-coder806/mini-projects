// snake game with oops
// date 25 may 2026

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

class snake
{
    int headX = 5, headY = 5;
    int foodX = 4, foodY = 2;
    int bodyX = 4, bodyY = 5;
int score = 0;
    public : 
    void grid()
    {
        system("cls");
        // int printgrid()
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (i == 0 || j == 0 || i == 9 || j == 9)
                {
                    cout << "# ";
                }
                else if (i == headY && j == headX)
                {
                    cout << ":)";
                }
                else if (i == foodY && j == foodX)
                {
                    cout << "F ";
                }
                else if (i == bodyY && j == bodyX)
                {
                    cout << "~ ";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
        cout << "SCORE:" << score << endl;
    }
    public: void snakepos (){
        char input;
        input = _getch();
        // int snakepos()
        bodyX = headX;
        bodyY = headY;
        switch (input)
        {
        case 'd':
            headX++;
            break;
        case 's':
            headY++;
            break;
        case 'a':
            headX--;
            break;
        case 'w':
            headY--;
            break;
        default:
            cout<<"inclaid input!!!!!!"<<endl;
        }
    }
    public: void food()
    {
        if (headX == foodX && headY == foodY)
        {
         ++score; 
        random:
            foodX = rand() % 8 + 1;
            foodY = rand() % 8 + 1;
            if (foodX == headX && foodY == headY)
                goto random;
        
        }
    }
    public: bool death()
    {
        if (headX == 0 || headX == 9 || headY == 0 || headY == 9)
        {
            return true;
        }
        if (headX == bodyX && headY == bodyY)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    // object
    snake s;
    // int main thing
    cout << "------WELCPME TO THE SNAKE GAME------ " << endl
         << ":) is snake head \t f is food \ controsl: w = up ; a = right ; s = down ; d= left \n EAT AS MANY FRUITS AS YOU CAN \n";
    bool dead = false;
    while (!s.death()){
        s.grid();
        s.snakepos();
        s.food();
    }
    return 0;
}
