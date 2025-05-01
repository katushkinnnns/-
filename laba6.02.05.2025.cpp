

#include <iostream>
#include <string>
#include <Windows.h>
#include "head1.h"
#include "head2.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Задание 1" << endl;
	string N_input;
	bool iscorrect = false;
	int N;
	while (iscorrect == false) {
		try {
			cout << "Введите количество участников: ";
			cin >> N_input;
			N = stoi(N_input);

			if (N > 0) {
				for (char c : N_input) {
					if (isdigit(c) == false) {
						iscorrect = false;
						cout << "Число  должно быть целым" << endl;
						break;
					}
					else {
						iscorrect = true;
					}
				}
			}
			else {
				cout << "Все значения должны быть больше нуля" << endl;
			}
		}
		catch (invalid_argument) {
			cout << "Попробуйте ещё раз" << endl;
		}
	}

	player* players = new player[N];

	for (int i = 0; i < N; i++) {
		players[i] = inputPlayer(N);
	}
	Winner(players, N);
	delete[] players;

	cout << "Задание 2" << endl;
	string K_input;
	iscorrect = false;
	int K;
	while (iscorrect == false) {
		try {
			cout << "Введите номер строку куда вставить пустую: ";
			cin >> K_input;
			K = stoi(K_input);

			if (K > 0) {
				for (char c : K_input) {
					if (isdigit(c) == false) {
						iscorrect = false;
						cout << "Число K должно быть вещественным" << endl;
						break;
					}
					else {
						iscorrect = true;
					}
				}
			}
			else {
				cout << "Все значения должны быть больше нуля" << endl;
			}
		}
		catch (invalid_argument) {
			cout << "Попробуйте ещё раз" << endl;
		}
	}

	string filename;
	cout << "Введите название файла" << endl;
	cin >> filename;

	processFile(filename + ".txt", K);

}


