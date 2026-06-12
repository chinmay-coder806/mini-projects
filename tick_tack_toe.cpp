// Tic Tac Toe
#include <bits/stdc++.h>
using namespace std;

class TicTacToe
{
    char arr[3][3] =
    {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

public:
    void grid()
    {
        cout << "\n";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << " " << arr[i][j] << " ";
                if (j < 2)
                    cout << "|";
            }

            if (i < 2)
                cout << "\n-----------\n";
        }
        cout << "\n\n";
    }

    bool placeMark(int pos, char mark)
    {
        int row = (pos - 1) / 3;
        int col = (pos - 1) % 3;

        if (arr[row][col] == 'X' || arr[row][col] == 'O')
            return false;

        arr[row][col] = mark;
        return true;
    }

    bool checkWin()
    {
        // Rows
        for (int i = 0; i < 3; i++)
        {
            if (arr[i][0] == arr[i][1] &&
                arr[i][1] == arr[i][2])
                return true;
        }

        // Columns
        for (int i = 0; i < 3; i++)
        {
            if (arr[0][i] == arr[1][i] &&
                arr[1][i] == arr[2][i])
                return true;
        }

        // Diagonals
        if (arr[0][0] == arr[1][1] &&
            arr[1][1] == arr[2][2])
            return true;

        if (arr[0][2] == arr[1][1] &&
            arr[1][1] == arr[2][0])
            return true;

        return false;
    }

    bool isDraw()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] != 'X' && arr[i][j] != 'O')
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    TicTacToe game;

    int pos;
    char currentPlayer = 'X';

    while (true)
    {
        game.grid();

        cout << "Player " << currentPlayer
             << ", enter position (1-9): ";

        cin >> pos;

        if (pos < 1 || pos > 9)
        {
            cout << "Invalid position!\n";
            continue;
        }

        if (!game.placeMark(pos, currentPlayer))
        {
            cout << "Position already occupied!\n";
            continue;
        }

        if (game.checkWin())
        {
            game.grid();
            cout << "Player " << currentPlayer
                 << " wins!\n";
            break;
        }

        if (game.isDraw())
        {
            game.grid();
            cout << "Match Draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}