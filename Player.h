#pragma once
#ifndef Player_H
#define Player_H
#include "Board.h"
#include "Coordinate.h"
typedef unsigned int uint; 

class Player
{
private:
	const string m_name;
public:
	char myChar; // Information hiding - sorry :-<
	Player();
	Player(const string name);
	const virtual string name() const;
	const virtual Coordinate play(const Board& board) = 0;
	const virtual string getChar() const;
	char mychar(Board b);
	char mychar() const;
	bool setChar(char c);
};
#endif //Player_H