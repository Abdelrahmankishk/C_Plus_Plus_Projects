#include <iostream>
using namespace std;

void DrawBoard(char** game);
char checkWinner(char** game);
void Game(char** game);

void main() {
	
	char** game = new char* [3];
	for (int i = 0; i < 3; i++) {
		game[i] = new char[3];
		for (int j = 0; j < 3; j++)
			game[i][j] = ' ';
	}
	DrawBoard(game);

	Game(game);
	
	for (int i = 0; i < 3; i++) {
		delete[]  game[i];
	}
	delete[] game;
}


void Game(char** game) {
	int counter = 0;
	bool X_turn = true;
	bool invalid = false;
	while (counter < 9) {
		int x, y;
		do
		{
			invalid = false;
			cout << "Enter the spot you want to play in: ";
			cin >> x >> y;
			if (x < 0 || x>2 || y < 0 || y>2) {
				cout << "Invalid Play try again!!" << endl;
				invalid = true;
				continue;
			}
			if (game[x][y] != ' ')
				cout << "This spot is not empty!!! Try again!" << endl;
		} while (invalid || game[x][y] != ' ');
		if (X_turn) {
			game[x][y] = 'X';
		}
		else {
			game[x][y] = 'O';
		}
		X_turn = !X_turn;
		DrawBoard(game);

		char c = checkWinner(game);
		if (c == 'X') {
			cout << "X is the winner !!" << endl;
			exit(0);
		}
		else if (c == 'O') {
			cout << "O is the winner !!" << endl;
			exit(0);
		}
		counter++;
	}
	cout << "Game OVER!! No winner" << endl;
}
void DrawBoard(char** game) {
	for (int i = 0; i < 7; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 45; j++) {
				cout << "=";
			}
		}
		else {
			for (int j = 0; j < 3; j++) {
				if (game[i / 2][j] != ' ' && j<3) {
					cout << "|      " << game[i / 2][j] << "      |";
				}
				else
				{
					cout << "|             |";
				}
			}
		}
		cout << endl;
	}
}

char checkWinner(char** game) {
	for (int i = 0; i < 3; i++) {
		if (game[0][i] != ' ' && game[0][i] == game[1][i] && game[1][i] == game[2][i])
			return game[0][i];
	}
	for (int i = 0; i < 3; i++) {
		if (game[i][0] != ' ' && game[i][0] == game[i][1] && game[i][1] == game[i][2])
			return game[i][0];
	}

	if (game[0][0] != ' ' && game[0][0] == game[1][1] && game[1][1] == game[2][2])
		return game[0][0];

	if (game[2][2] != ' ' && game[2][2] == game[1][1] && game[1][1] == game[0][0])
		return game[2][2];

	return ' ';
}