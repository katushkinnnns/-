
#include <iostream>
#include <string>

using namespace std;

struct sports {
	int fetching = 0;
	int swimming = 0;
	int concur = 0;
	int shooting = 0;
	int running = 0;

};

struct player {
	string surName;
	sports places;
};

player inputPlayer(int N) {
	player e;
	bool iscorrect = false;
	string fetching_input, swimming_input, concur_input, shooting_input, running_input;


	while (iscorrect == false) {
		try {
			cout << "Введите информацию об участнике" << endl;

			bool isSurNamecorrect = false;
			while (isSurNamecorrect == false) {
				cout << "Введите фамилию: ";
				cin >> e.surName;
				if (string::npos != e.surName.find_first_of("0123456789!№;%:?,.+-")) {
					cout << "Введите корректную фамилию" << endl;
					isSurNamecorrect = false;
				}
				else {
					isSurNamecorrect = true;
				}
			}

			cout << "Введите место по фехтованию: ";
			cin >> fetching_input;
			e.places.fetching = stoi(fetching_input);

			cout << "Введите место по плаванию: ";
			cin >> swimming_input;
			e.places.swimming = stoi(swimming_input);

			cout << "Введите место по конкуру: ";
			cin >> concur_input;
			e.places.concur = stoi(concur_input);

			cout << "Введите место по стрельбе: ";
			cin >> shooting_input;
			e.places.shooting = stoi(shooting_input);

			cout << "Введите место по бегу: ";
			cin >> running_input;
			e.places.running = stoi(running_input);
			if (isSurNamecorrect == true && e.places.fetching > 0 && e.places.swimming > 0 && e.places.concur > 0 && e.places.shooting > 0 && e.places.running > 0) {
				if (e.places.fetching <= N && e.places.swimming <= N && e.places.shooting <= N && e.places.concur <= N && e.places.running <= N) {
					iscorrect = true;
				}
				else {
					iscorrect = false;
					cout << "Место не должно превышать кол-во участников" << endl;
				}
			}
			else {
				iscorrect = false;
				cout << "Введите корректные значения" << endl;
			}
		}
		catch (invalid_argument) {
			cout << "Попробуйте ещё раз" << endl;
		}
	}
	return e;
}

void Winner(player* players, int N) {
	cout << "\nПобедители:\n";
	bool winner_fnd = false;
	cout << "Плавание: ";
	for (int i = 0; i < N; i++) {
		if (players[i].places.swimming == 1) {
			cout << players[i].surName << " ";
			winner_fnd = true;
		}
	}
	if (winner_fnd == false) {
		cout << "Победитель не выявлен" << endl;
	}
	cout << endl;
	winner_fnd = false;

	cout << "Фехтование: ";
	for (int i = 0; i < N; i++) {
		if (players[i].places.fetching == 1) {
			cout << players[i].surName << " ";
			winner_fnd = true;
		}
	}
	if (winner_fnd == false) {
		cout << "Победитель не выявлен" << endl;
	}
	cout << endl;
	winner_fnd = false;


	cout << "Конкур: ";
	for (int i = 0; i < N; i++) {
		if (players[i].places.concur == 1) {
			cout << players[i].surName << " ";
			winner_fnd = true;
		}
	}
	if (winner_fnd == false) {
		cout << "Победитель не выявлен" << endl;
	}
	cout << endl;
	winner_fnd = false;


	cout << "Стрельба: ";
	for (int i = 0; i < N; i++) {
		if (players[i].places.shooting == 1) {
			cout << players[i].surName << " ";
			winner_fnd = true;
		}
	}
	if (winner_fnd == false) {
		cout << "Победитель не выявлен" << endl;
	}
	cout << endl;
	winner_fnd = false;


	cout << "Бег: ";
	for (int i = 0; i < N; i++) {
		if (players[i].places.running == 1) {
			cout << players[i].surName << " ";
			winner_fnd = true;
		}
	}
	if (winner_fnd == false) {
		cout << "Победитель не выявлен" << endl;
	}
	cout << endl;
	winner_fnd = false;
}