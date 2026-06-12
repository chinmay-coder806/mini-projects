
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    enum Choice
    {
        rock = 1,
        paper,
        scissors
    };

    int user_choice;
    int player = 0, computer = 0;

    cout << "1. Rock  2. Paper  3. Scissors  (Any other number to exit)\n";
    cout << "Rock Paper Scissors !!!\n";

    srand(time(0)); // Seed random generator ONCE

    while (1)
    {
        int pc_choice = rand() % 3 + 1;

        cout << "\nEnter your choice: ";
        cin >> user_choice;

        // Exit condition
        if (user_choice < 1 || user_choice > 3)
        {
            cout << "Exiting game...\n";
            break;
        }

        // Show computer's choice
        cout << "Computer chose: ";

        if (pc_choice == rock)
            cout << "Rock\n";
        else if (pc_choice == paper)
            cout << "Paper\n";
        else
            cout << "Scissors\n";

        switch (user_choice)
        {
        case rock:
            if (pc_choice == rock)
            {
                cout << "Tie :|\n";
            }
            else if (pc_choice == scissors)
            {
                cout << "You won XD\n";
                player++;
            }
            else
            {
                cout << "I won ;D\n";
                computer++;
            }
            break;

        case paper:
            if (pc_choice == paper)
            {
                cout << "Tie :|\n";
            }
            else if (pc_choice == rock)
            {
                cout << "You won XD\n";
                player++;
            }
            else
            {
                cout << "I won ;D\n";
                computer++;
            }
            break;

        case scissors:
            if (pc_choice == scissors)
            {
                cout << "Tie :|\n";
            }
            else if (pc_choice == paper)
            {
                cout << "You won XD\n";
                player++;
            }
            else
            {
                cout << "I won ;D\n";
                computer++;
            }
            break;
        }

        cout << "\nScores:\n";
        cout << "Player: " << player << endl;
        cout << "Computer: " << computer << endl;
    }

    return 0;
}