#include <iostream>
using namespace std;

int main() {
	char player1[100];
	cout << "PLAYER 1 ENTER YOUR NAME : ";
	cin.getline(player1, 100);
	char player2[100];
	cout << "PLAYER 2 ENTER YOUR NAME : ";
	cin.getline(player2, 100);
	char board[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	int player = 1;
	int choice;
	bool isCompleted = false;
	cout << "1" << " | " << "2" << " | " << "3" << endl;
	cout << "-----------" << endl;
	cout << "4" << " | " << "5" << " | " << "6" << endl;
	cout << "-----------" << endl;
	cout << "7" << " | " << "8" << " | " << "9" << endl;
	do {



		cout << "Player " << player << ", enter the number of your move: ";
		cin >> choice;


		if (board[choice - 1] == 'X' || board[choice - 1] == 'O') {
			cout << "Invalid move! Try again." << endl;
			continue;
		}
		if (choice<1||choice>9) {
			cout << "Invalid move! Try again." << endl;
			continue;
		}


		if (player == 1)
			board[choice - 1] = 'X';
		else
			board[choice - 1] = 'O';


		player = 3 - player;


		for (int i = 0; i < 3; i++) {
			if (board[i * 3] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2] && board[i * 3] != ' ') {
				cout << endl << player1 << " wins!" << endl;
				isCompleted = true;
				break;
			}
			if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != ' ') {
				cout << endl << player2 << " wins!" << endl;
				isCompleted = true;
				break;
			}

		}

		if ((board[0] == 'X' && board[4] == 'X' && board[8] == 'X') || (board[2] == 'X' && board[4] == 'X' && board[6] == 'X')) {
			cout << endl << player1 << " wins!" << endl;
			isCompleted = true;
			continue;
		}
		if ((board[0] == 'O' && board[4] == 'O' && board[8] == 'O') || (board[2] == 'O' && board[4] == 'O' && board[6] == 'O')) {
			cout << endl << player2 << " wins!" << endl;
			isCompleted = true;
			continue;
		}

		int count = 0;
		for (int i = 0; i < 9; i++) {
			if (board[i] == 'X' || board[i] == 'O') {
				count++;
			}
		}
		if (count == 9) {
			cout << "It's a draw!" << endl;
			isCompleted = true;
			break;
		}

		cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
		cout << "-----------" << endl;
		cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
		cout << "-----------" << endl;
		cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
	} while (isCompleted != true);



	system("pause");
	return 0;
}