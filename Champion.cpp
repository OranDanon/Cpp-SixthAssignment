#include "Champion.h"

Champion::Champion() : Player("Roee and Oran")
{
}

const string Champion::name() const
{
	return "Roee and Oran";
}

const Coordinate Champion::play(const Board & board)
{
	size_t last = board.size() - 1;
	if (myChar == 'X')
	{
		for (size_t i = 0; i < board.size(); i++)
		{
			if (board[{i, i}] == '.')
			{
				return { i,i };
			}
		}
	}
	else
	{
		if (board[{0, 0}] == 'X' && board[{0, 1}] == 'X')
		{
			for (size_t i = 0; i < board.size(); i++)
			{
				if (board[{i, last}] == '.')
				{
					return {i, last};
				}
			}
		}
		else if (board[{0, 0}] == 'X' && board[{1, 0}] == 'X')
		{
			for (size_t i = 0; i < board.size(); i++)
			{
				if (board[{last, i}] == '.')
				{
					return { last, i };
				}
			}
		}
	}
	return Coordinate(last, last);
}
