#pragma once
#include <list>
#include "memory"
#include "../Pieces/Piece.hpp"
using namespace std;

enum class Team;

class King;

class Move;

class Board
{
    // Member variables
    shared_ptr<Piece> m_board[8][8];
    Team m_turn; // White or black player's turn
    vector<shared_ptr<Piece>> m_whitePieces;
    vector<shared_ptr<Piece>> m_blackPieces;
    shared_ptr<King> m_whiteKing;
    shared_ptr<King> m_blackKing;
    bool m_isFlipped = false;

    // Private functions
    void removeIllegalMoves(vector<Move>&, shared_ptr<Piece>&);

    public:
    Board(); // Constructor
    void reset(); // Resets the board

    // Getters and setters
    shared_ptr<Piece> getBoardTile(int x, int y) const { return m_board[y][x]; }
    shared_ptr<King> getKing() const;
    Team getTurn() const { return m_turn; }
    void setBoardTile(int, int, shared_ptr<Piece>&, bool record = true);
    void resetBoardTile(int, int, bool record_ = true);
    void switchTurn();

    // Utility functions
    vector<Move> possibleMovesFor(shared_ptr<Piece>&);
    vector<Move> calculateAllMoves();
    bool kingIsChecked();
    void addPiece(shared_ptr<Piece>&);
};
