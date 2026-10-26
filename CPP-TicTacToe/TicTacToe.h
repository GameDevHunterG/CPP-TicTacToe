#pragma once

#include "Game.h"

class TicTacToe : public Game
{

private:

	int m_player = 0;
	char m_board[9];

public:

	TicTacToe() 
	{ 
		for (int i = 0; i < 9; i++) m_board[i] = ' '; 
		m_player = 1;
	}

	bool IsGameOver() const;

	void TakeTurn();

	void Display() const;

};

