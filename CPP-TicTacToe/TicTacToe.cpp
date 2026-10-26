#include "TicTacToe.h"
#include <iostream>

void TicTacToe::Display() const
{
	system("cls");

	std::cout << "Welcome to Tic Tac Toe!\n\n";
	std::cout << "(1-3) \t " << TicTacToe::m_board[0] << "|" << TicTacToe::m_board[1] << "|" << TicTacToe::m_board[2] << "\n";
	std::cout << "\t-------\n";
	std::cout << "(4-6) \t " << TicTacToe::m_board[3] << "|" << TicTacToe::m_board[4] << "|" << TicTacToe::m_board[5] << "\n";
	std::cout << "\t-------\n";
	std::cout << "(7-9) \t " << TicTacToe::m_board[6] << "|" << TicTacToe::m_board[7] << "|" << TicTacToe::m_board[8] << "\n";

	if (TicTacToe::IsGameOver())
	{
		std::cout << "Game Over!\n";
		return;
	}

	std::cout << "\nCurrent turn: " << (TicTacToe::m_player == 1 ? "X" : "O") << "\n";
}

void TicTacToe::TakeTurn()
{
	int input;
	std::cout << "\nEnter the number (1-9) of the space you want to play: ";
	std::cin >> input;

	bool isValid = false;
	while (!isValid)
	{
		if (input < 1 || input > 9)
		{
			std::cout << "That number is outside the range of the board. Please pick a different number (1-9): ";
			std::cin >> input;
		}
		else if (TicTacToe::m_board[input - 1] != ' ')
		{
			std::cout << "That space is already taken. Please pick a different space (1-9): ";
			std::cin >> input;
		}
		else isValid = true;
	}

	TicTacToe::m_board[input - 1] = TicTacToe::m_player == 1 ? 'X' : 'O';
	TicTacToe::m_player = TicTacToe::m_player == 1 ? 2 : 1;
}

bool TicTacToe::IsGameOver() const
{
	if ((TicTacToe::m_board[0] == 'X' && TicTacToe::m_board[1] == 'X' && TicTacToe::m_board[2] == 'X')
		|| (TicTacToe::m_board[3] == 'X' && TicTacToe::m_board[4] == 'X' && TicTacToe::m_board[5] == 'X')
		|| (TicTacToe::m_board[6] == 'X' && TicTacToe::m_board[7] == 'X' && TicTacToe::m_board[8] == 'X')
		|| (TicTacToe::m_board[0] == 'X' && TicTacToe::m_board[3] == 'X' && TicTacToe::m_board[6] == 'X')
		|| (TicTacToe::m_board[1] == 'X' && TicTacToe::m_board[4] == 'X' && TicTacToe::m_board[7] == 'X')
		|| (TicTacToe::m_board[2] == 'X' && TicTacToe::m_board[5] == 'X' && TicTacToe::m_board[8] == 'X')
		|| (TicTacToe::m_board[0] == 'X' && TicTacToe::m_board[4] == 'X' && TicTacToe::m_board[8] == 'X')
		|| (TicTacToe::m_board[2] == 'X' && TicTacToe::m_board[4] == 'X' && TicTacToe::m_board[6] == 'X'))
	{
		std::cout << "\nX wins!\n";
		return true;
	}
	else if ((TicTacToe::m_board[0] == 'O' && TicTacToe::m_board[1] == 'O' && TicTacToe::m_board[2] == 'O')
		|| (TicTacToe::m_board[3] == 'O' && TicTacToe::m_board[4] == 'O' && TicTacToe::m_board[5] == 'O')
		|| (TicTacToe::m_board[6] == 'O' && TicTacToe::m_board[7] == 'O' && TicTacToe::m_board[8] == 'O')
		|| (TicTacToe::m_board[0] == 'O' && TicTacToe::m_board[3] == 'O' && TicTacToe::m_board[6] == 'O')
		|| (TicTacToe::m_board[1] == 'O' && TicTacToe::m_board[4] == 'O' && TicTacToe::m_board[7] == 'O')
		|| (TicTacToe::m_board[2] == 'O' && TicTacToe::m_board[5] == 'O' && TicTacToe::m_board[8] == 'O')
		|| (TicTacToe::m_board[0] == 'O' && TicTacToe::m_board[4] == 'O' && TicTacToe::m_board[8] == 'O')
		|| (TicTacToe::m_board[2] == 'O' && TicTacToe::m_board[4] == 'O' && TicTacToe::m_board[6] == 'O'))
	{
		std::cout << "\nO wins!\n";
		return true;
	}
	else if (TicTacToe::m_board[0] != ' ' && TicTacToe::m_board[1] != ' ' && TicTacToe::m_board[2] != ' '
		&& TicTacToe::m_board[3] != ' ' && TicTacToe::m_board[4] != ' ' && TicTacToe::m_board[5] != ' '
		&& TicTacToe::m_board[6] != ' ' && TicTacToe::m_board[7] != ' ' && TicTacToe::m_board[8] != ' ')
	{
		std::cout << "\nIt's a tie!\n";
		return true;
	}
	else return false;
}