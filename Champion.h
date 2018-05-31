#pragma once
#ifndef Champion_H
#define Champion_H
#include <string.h>
#include <string>
#include "Player.h"

using namespace std;

class Champion : public Player
{
private:

public:
	Champion();
	const string name() const override;
	const Coordinate play(const Board& board) override;
};

#endif ///Champion_H