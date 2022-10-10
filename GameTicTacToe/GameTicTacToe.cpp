#include <iostream>

using namespace std;
#define X 'X'
#define O 'O'

int nS;
int nF = nS = 0;
char firstPlayer[50];
char secondPlayer[50];

void EnterName()
{
	if (firstPlayer) {
		cout << "Name of the first player:";
		cin >> firstPlayer;
	}
	if (secondPlayer) {
		cout << "Name of the second player: ";
		cin >> secondPlayer;
	}
}

void ChoiceChar()
{
	char c;
	if (firstPlayer != NULL || secondPlayer != NULL) {
		cout << "Mark of the " << firstPlayer << "? (X or O) \n";
		cin >> c;
		(c == 'X') ? nF = 1 : nS = 1;
	}
	else
		cout << "Wrong input.\n";
}

void menu()
{
	char c;
	bool flag = true;
	do
	{
		cout << "Menu:\n\n";
		cout << "1. Enter name" << firstPlayer << " " << secondPlayer << "\n";
		cout << "2. Choose a mark for the player and start the game\n";
		cout << "3. Enter for exit\n";

		cin >> c;
		switch (c)
		{
		case '1':
			EnterName();
			system("cls");
			break;
		case '2':
			ChoiceChar();
			flag = false;
			break;
		case '3':
			exit(0);
			break;
		default:
			break;
		}
	} while (c != '3' && flag);
}

char board[3][3];
// отображение поля
void show() {
	cout << "  1 2 3 \n";
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1;
		for (int j = 0; j < 3; j++)
		{
			cout << "|" << board[i][j];
		}
		cout << "|\n";
	}
}
//условия победы
bool win()
{
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != '_') return false;
	if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != '_') return false;
	if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != '_') return false;

	if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != '_') return false;
	if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != '_') return false;
	if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != '_') return false;

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '_') return false;
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '_') return false;

	return true;
}

void stepPlayer(int i)
{
	int c1, c2;
	do {
		cout << "Выберете значение по горизонтали: ";
		cin >> c1;
		cout << "Выберете значение по вертикали: ";
		cin >> c2;
		if (c1 > 3 && c2 > 3) {
			cout << "Неверное значение\n";
			continue;
		}
		if (c1 < 0 && c2 < 0) {
			cout << "Неверное значение\n";
			continue;
		}
		if (board[c1 - 1][c2 - 1] == 'X' || board[c1 - 1][c2 - 1] == 'O')
		{
			cout << "Клетка занята. Выберете другую клетку\n";
		}
	} while (board[c1 - 1][c2 - 1] != '_');
	i ? board[--c1][--c2] = X : board[--c1][--c2] = O;
	show();
}


int main()
{
	setlocale(LC_ALL, "");
	int count = 0;
	// заполняем массив значениями
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = '_';
		}
	}
	menu();
	show();
	while (win() && count != 9)
	{
		cout << "Ход игрока " << firstPlayer << endl;
		stepPlayer(nF);
		if (!win()) {
			cout << "Игрок " << firstPlayer << " победил!\n";
			break;
		}
		count++;
		if (count == 9) cout << "Ничья!\n";
		cout << "Ход игрока " << secondPlayer << endl;
		stepPlayer(nS);
		if (!win()) {
			cout << "Игрок " << firstPlayer << " победил!\n";
			break;
		}
		count++;
		if (count == 9) cout << "Ничья!\n";
	}
}