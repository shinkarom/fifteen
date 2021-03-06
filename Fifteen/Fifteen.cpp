// Fifteen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "FifteenGame.h"
#include "Fifteen.h"

FifteenGame Game;

void DrawGame(FifteenGame arg)
{
	cout << endl;
	for (int y = 0;y < 4;y++) {
		for (int x = 0;x < 4;x++)
		{
			try
			{
				auto g = Game.GetCell(x, y);
				if (g < 10) cout << " ";
				if (g == 16) cout << "\t";
				else cout << g << "\t";
			}
			catch (const std::exception& e)
			{
				cout << "\nException: " << e.what() << "\n";
			}

		}
		cout << "\n";
	}
	cout << endl;
}

int main()
{
	DrawGame(Game);
	//TODO 3. Repeat turns.
	int turn;
	string input;
	while (true)
	{

		cout << "Your turn, Maestro (0 to end the game): ";
		getline(cin, input);
		stringstream myStream(input);
		if (!(myStream >> turn))
		{
			cout << "\"" << input << "\" is most definitely not a number." << endl;
			continue;
		}
		if (turn == 0) { cout << "Thanks for playing!"; return 0; }

		if (!Game.IsALegalMove(turn)) { cout << "Unfortunately, \"" << turn << "\" is not a legal move.\n";continue; }
		Game.MakeTheMove(turn);
		DrawGame(Game);
		if (Game.IsBoardWon()) { cout << "Congratulations for solving the puzzle!"; exit(0); }
	}
	return 0;
}

