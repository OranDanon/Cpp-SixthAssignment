#include "TicTacToe.h"
#include "DummyPlayers.h"

#include "Champion.h"

void printResults(const TicTacToe& game) {
	cout << endl << "The final board is " << endl << game.board();
	cout << "And the winner is " << game.winner().name()
		<< ", playing as " << game.winner().getChar() << "!" << endl;
}

void playAndPrintResults(TicTacToe& game, Player& xPlayer, Player& oPlayer) {
	game.play(xPlayer, oPlayer);
	printResults(game);
}

void playAndPrintWinner(TicTacToe& game, Player& xPlayer, Player& oPlayer) {
	game.play(xPlayer, oPlayer);
	cout << "The winner is " << game.winner().name()
		<< ", playing as " << game.winner().getChar() << "!" << endl;
}


int main() {
	TicTacToe game(3);       // Initializes a game on a 4x4 board
	TicTacToe game2(5);
	XYPlayer player1;
	YXPlayer player2;
	IllegalPlayer player3;
	ExceptionPlayer player4;
	XYPlayer player5;

	playAndPrintResults(game, player1, player2);
	game.board().draw(50);
	/*
	The final board is
	XXXX
	O...
	O...
	O...
	And the winner is XYPlayer, playing as X!
	*/

	playAndPrintResults(game, player2, player1);
	game.board().draw(100);
	/*
	The final board is
	XOOO
	X...
	X...
	X...
	And the winner is YXPlayer, playing as X!
	*/

	playAndPrintResults(game, player1, player3);
	game.board().draw(100);
	/*
	The final board is
	X...
	....
	....
	....
	And the winner is XYPlayer, playing as X!
	*/


	playAndPrintResults(game, player3, player1);
	game.board().draw(100);
	/*
	The final board is
	XO..
	....
	....
	....
	And the winner is XYPlayer, playing as O!
	*/

	playAndPrintResults(game, player2, player4);
	game.board().draw(100);
	/*
	The final board is
	X...
	....
	....
	....
	And the winner is YXPlayer, playing as X!
	*/

	playAndPrintResults(game, player4, player2);
	game.board().draw(100);
	/*
	The final board is
	....
	....
	....
	....
	And the winner is YXPlayer, playing as O!
	*/

	playAndPrintResults(game2, player1, player5);
	game.board().draw(100);


	Champion champion;
	playAndPrintWinner(game, champion, player1);
	// The winner is <your name>, playing as X!
	playAndPrintWinner(game, player1, champion);
	// The winner is <your name>, playing as O!
	playAndPrintWinner(game, champion, player2);
	// The winner is <your name>, playing as X!
	playAndPrintWinner(game, player2, champion);
	// The winner is <your name>, playing as O!
	playAndPrintWinner(game, champion, player3);
	// The winner is <your name>, playing as X!
	playAndPrintWinner(game, player3, champion);
	// The winner is <your name>, playing as O!
	playAndPrintWinner(game, champion, player4);
	// The winner is <your name>, playing as X!
	playAndPrintWinner(game, player4, champion);
	// The winner is <your name>, playing as O!
	game.board().draw(100);

	return 0;
}