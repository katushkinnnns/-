#include <iostream>
#include <string>
#include <sstream>
#include <limits> 

using namespace std;

int inputInt(const string& prompt) {
    int number;
    string input;

    while (true) {
        cout << prompt;
        getline(cin, input);

        stringstream ss(input);
        if (ss >> number && ss.eof()) { 
            return number;
        }
        else {
            cout << "Ошибка! Введите целое число.\n";
            cin.clear();
        }
    }
}

int SumRange(int A, int B) {
    if (A > B) {
        return 0;
    }

    int sum = 0;
    for (int i = A; i <= B; ++i) {
        sum += i;
    }

    return sum;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int A = inputInt("Введите целое число A: ");
    int B = inputInt("Введите целое число B: ");
    int C = inputInt("Введите целое число C: ");

    int sumAB = SumRange(A, B);
    cout << "Сумма чисел от " << A << " до " << B << ": " << sumAB << endl;

    int sumBC = SumRange(B, C);

    if (B > C) {
        cout << "Сумма чисел от " << B << " до " << C << ": 0" << endl;
    }
    else {
        cout << "Сумма чисел от " << B << " до " << C << ": " << sumBC << endl;
    }

    return 0;
}
