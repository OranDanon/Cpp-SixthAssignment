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
	size_t last_line = board.size() - 1;
	for (size_t i = 0; i < board.size(); i++)
	{
		if (board[{i, i}] == '.')
		{
			return Coordinate(i, i);
		}
	}
	return Coordinate(0,0);
}
