#include <iostream>

#include "../include/TicTacToe.h"

using namespace TicTacToe;

class TicTacToeBoard : public ITicTacToeBoard
{
private:
    std::array<std::array<char, 3>, 3> board;
    Player currentPlayer;


public:

    TicTacToeBoard() : board({{{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}})
    {
        currentPlayer = Player::X;
    }

    Player currentlyPlayingPlayer()
    {
        return currentPlayer;
    }

    char showPlayerChar(Player player) const override
    {
        return (player == Player::X) ? 'X' : 'O';
    }

    void printBoard() const override
    {
        std::cout << "  1 2 3" << std::endl;
        for (int i = 0; i < 3; i++)
        {
            std::cout << (char)('a' + i) << " ";
            for (int j = 0; j < 3; j++)
            {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool isValidMove(int row, int col) const override
    {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
    }

    bool makeMove(int row, int col) override
    {
        if (!isValidMove(row, col))
        {
            return false;
        }

        // Create a new board with the move applied
        TicTacToeBoard newBoard = *this;
        newBoard.board[row][col] = newBoard.showPlayerChar(newBoard.currentPlayer);
        newBoard.currentPlayer = (newBoard.currentPlayer == Player::X) ? Player::O : Player::X;

        // Replace the current board with the new one
        *this = newBoard;
        return true;
    }

    bool hasWon(Player player) const override
    {
        char playerChar = showPlayerChar(player);

        // Check rows
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == playerChar && board[i][1] == playerChar && board[i][2] == playerChar)
            {
                return true;
            }
        }

        // Check columns
        for (int i = 0; i < 3; i++)
        {
            if (board[0][i] == playerChar && board[1][i] == playerChar && board[2][i] == playerChar)
            {
                return true;
            }
        }

        // Check diagonals
        if (board[0][0] == playerChar && board[1][1] == playerChar && board[2][2] == playerChar)
        {
            return true;
        }
        if (board[2][0] == playerChar && board[1][1] == playerChar && board[0][2] == playerChar)
        {
            return true;
        }

        return false;
    }

    bool isGameOver() const override
    {
        return hasWon(Player::X) || hasWon(Player::O) || showEmptySpaces().empty();
    }

    std::vector<std::pair<int, int>> showEmptySpaces() const override
    {
        std::vector<std::pair<int, int>> emptySpaces;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    emptySpaces.emplace_back(i, j);
                }
            }
        }
        return emptySpaces;
    }
};