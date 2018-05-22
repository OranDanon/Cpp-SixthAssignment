#include "Player.h"


const char Player::getChar() const
{
	return myChar;
}

char Player::mychar(Board b)
{
	if (b.isEmpty())
	{
		this->myChar = 'X';
	}
	this->myChar = 'O';
	return this->myChar;
}

char Player::mychar() const
{
	return this->myChar;
}

bool Player::setChar(char c)
{
	if (c != 'X' || c!= 'O')
	{
		this->myChar = c;
		return true;
	}
	return false;
}


Player::Player(): m_name("")
{
}

Player::Player(const string name) : m_name(name)
{
}

const string Player::name() const
{
	return m_name;
}

