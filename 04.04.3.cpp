#include <iostream>
#include <limits>  
#include <sstream> 
#include <string>

using namespace std;

int inputNaturalNumber(const string& prompt) {
    int number;
    string input;

    while (true) {
        cout << prompt;
        getline(cin, input);

        stringstream ss(input);
        if (ss >> number && ss.eof() && number > 0) {
            return number;
        }
        else {
            cout << "Ошибка! Введите натуральное число\n";
            cin.clear();
        }
    }
}

int sumOfDigits(int n) {
    if (n == 0) {
        return 0; 
    }
    else {
        return (n % 10) + sumOfDigits(n / 10);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int N = inputNaturalNumber("Введите натуральное число N: ");

    int digitSum = sumOfDigits(N);

    cout << "Сумма цифр числа " << N << " равна: " << digitSum << endl;

    return 0;
}
