#pragma once
#ifndef TicTacToe_H
#define TicTacToe_H

#include "Board.h"
#include "Player.h"
#include "Champion.h"
class TicTacToe final
{
private:
	Player* p1;
	Player* p2;
	Player* winnerr;
	Board b;

	static const size_t nextTurn(size_t& t);
	static void printWinner(Player& p);
	const bool isWinner(size_t t) const;
public:
	TicTacToe(size_t size);
	Player& play(Player& p1, Player& p2);
	Player& winner() const;
	Board board() const;

};

#endif /// TicTacToe_H