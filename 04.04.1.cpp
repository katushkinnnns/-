#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <algorithm> 

using namespace std;

double inputDouble(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);

        replace(input.begin(), input.end(), '.', ',');

        try {
            size_t pos;
            double value = stod(input, &pos);

            if (pos == input.size()) {
                return value;
            }
        }
        catch (...) {
        }

        cout << "Ошибка! Введите число повторно! \n";
    }
}

int inputInt(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);

        try {
            size_t pos;
            int value = stoi(input, &pos);

            if (pos == input.size()) {
                return value;
            }
        }
        catch (...) {
        }

        cout << "Ошибка! Введите целое число!\n";
    }
}

double Power2(double A, int N) {
    double result = 1.0;
    int absN = abs(N);

    for (int i = 0; i < absN; i++) {
        result *= A;
    }

    if (N >= 0) {
        return result;
    }
    else {
        return (1.0 / result);
    }

}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Программа вычисляет A^N (A - вещественное число, N - целое число)\n";

    double A = inputDouble("Введите основание A: ");

    int N = inputInt("Введите степень N: ");

    double result = Power2(A, N);
    cout << A << " ^ " << N << " = " << result << endl;

    return 0;
}
