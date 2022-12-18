#include <iostream>

#include "TicTacToe.cpp"


int main()
{
    TicTacToeBoard board;

    while (!board.isGameOver())
    {
        board.printBoard();

        char rowInput;
        int colInput;
        std::cout << "Player " << board.showPlayerChar(board.currentlyPlayingPlayer()) << ", enter your move (row column): ";
        std::cin >> rowInput >> colInput;

        int row = rowInput - 'a';
        int col = colInput - 1;
        if (!board.makeMove(row, col))
        {
            std::cout << "Invalid move!" << std::endl;
        }
    }

    board.printBoard();
    if (board.hasWon(TicTacToe::Player::X))
    {
        std::cout << "Player X has won!" << std::endl;
    }
    else if (board.hasWon(TicTacToe::Player::O))
    {
        std::cout << "Player O has won!" << std::endl;
    }
    else
    {
        std::cout << "It's a draw!" << std::endl;
    }

    getchar();
    getchar();

    return 0;
}