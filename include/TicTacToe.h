#include <array>
#include <vector>


namespace TicTacToe
{
    enum class Player { X, O };

    // An interface for a tic-tac-toe board
    class ITicTacToeBoard
    {
    public:
        virtual char showPlayerChar(Player player) const = 0;
        virtual void printBoard() const = 0;
        virtual bool isValidMove(int row, int col) const = 0;
        virtual bool makeMove(int row, int col) = 0;
        virtual bool hasWon(Player player) const = 0;
        virtual bool isGameOver() const = 0;
        virtual std::vector<std::pair<int, int>> showEmptySpaces() const = 0;
    };
};