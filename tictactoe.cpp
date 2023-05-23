#include <iostream>
#include <vector>
using namespace std;

void show(const vector<vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool checkWin(const vector<vector<char>> &board, char player)
{

    for (const auto &row : board)
    {
        if (row[0] == player && row[1] == player && row[2] == player)
        {
            return true;
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }

    return false;
}

int main()
{

    vector<vector<char>> board(3, vector<char>(3, ' '));

    char cplayer = 'X';
    int turns = 0;

    while (1)
    {

        cout << "Current board:" << endl;
        show(board);

        int row, col;
        cout << "Player " << cplayer << ", enter your move (row and column): ";
        cin >> row >> col;
        row--, col--;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
        {
            cout << "This move is out of range. Try again ." << endl;
            continue;
        }

        board[row][col] = cplayer;
        turns++;

        if (checkWin(board, cplayer))
        {
            cout << "Player " << cplayer << " wins!" << endl;
            show(board);
            break;
        }

        if (turns >= 9)
        {
            cout << "It's a tie!" << endl;
            break;
        }

        cplayer = (cplayer == 'X') ? 'O' : 'X';
    }
}
