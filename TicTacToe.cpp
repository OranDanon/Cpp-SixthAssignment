#include "TicTacToe.h"

const size_t TicTacToe::nextTurn(size_t& t)
{
	t = (t + 1) % 2;
	return t;
}

void TicTacToe::printWinner(Player& p)
{
	cout << p.name() << " Won" << endl;
}

const bool TicTacToe::isExist(Coordinate & cor) const
{
	size_t index = cor.index(b.size());
	if (forbidden[index] != 0)
		return true;
	return false;
}

const bool TicTacToe::isWinner(size_t t) const
{
	char c;
	bool flag1 = true, flag2 = true, flag3 = true;
	if (t == 0)
	{
		c = 'X';
	}
	else
	{
		c = 'O';
	}
	for (size_t i = 0; i < b.size(); i++)
	{
		for (size_t j = 0; j < b.size(); j++)
		{
			if (i == j && b[{i, i}] != c)
			{
				flag1 = false;
			}
			if (b[{i,j}] != c)
			{
				flag2 = false;
			}
			if (b[{j,i}] != c)
			{
				flag3 = false;
			}
		}
		if (flag2 || flag3)
		{
			return true;
		}
	}
	return flag3;
}

const bool TicTacToe::clearForbidden()
{
	for (size_t i = 0; i < b.size(); i++)
	{
		for (size_t j = 0; j < b.size(); j++)
		{
			forbidden[i * b.size() + j] = 0;
		}
	}
	return true;
}

TicTacToe::TicTacToe(size_t size) :b(size)
{
	forbidden = new int[size*size]();
}

Player& TicTacToe::play(Player& p1, Player& p2)
{
	size_t turn = 0;
	Coordinate index;
	Player* players [2] = { &p1, &p2 };
	this->clearForbidden();
	b.clear();
	//cout << b << endl;
	p1.setChar('X');
	p2.setChar('O');
	while (!b.isFull())
	{
		try
		{
			index = players[turn]->play(b);
			if (isExist(index))
			{
				throw IllegalCoordinateException(index, "This index is forbidden");
			}
			forbidden[index.index(static_cast<int>(b.size()))] = 1;
			std::pair<size_t, size_t>temp (index.x(), index.y());
			b[temp] = players[turn]->mychar();
			//cout << b << endl;
		}
		catch (const IllegalCharException& ex) 
		{
			cout << "Illegal char: " << ex.theChar() << endl;
			nextTurn(turn);
			winnerr = players[turn];
			return *winnerr;
		}
		catch (const IllegalCoordinateException& ex) 
		{
			cout << "Illegal coordinate: " << ex.theCoordinate() << endl;
			nextTurn(turn);
			winnerr = players[turn];
			return *winnerr;
		}
		catch (...)
		{
			nextTurn(turn);
			winnerr = players[turn];
			return *winnerr;
		}
		if (isWinner(turn))
		{
			winnerr = players[turn];
			return *winnerr;
		}
		nextTurn(turn);
	}
	winnerr = &p2;
	printWinner(*winnerr);
	return *winnerr;
}

Player & TicTacToe::winner() const
{
	return *winnerr;
}

Board TicTacToe::board() const
{
	/*ostringstream os;
	os << b;
	return os.str();*/
	return b;
}

TicTacToe::~TicTacToe()
{
	delete [] forbidden;
}