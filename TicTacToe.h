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
	int *forbidden;

	static const size_t nextTurn(size_t& t);
	static void printWinner(Player& p);
	const bool isExist(Coordinate& cor) const;
	const bool isWinner(size_t t) const;
	const bool clearForbidden();
public:
	TicTacToe(size_t size);
	Player& play(Player& p1, Player& p2);
	Player& winner() const;
	string board() const;

};

#endif /// TicTacToe_H