#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool isFileEmpty(string filename) {
    ifstream file(filename);
    return file.peek() == ifstream::traits_type::eof(); // Проверку взял из интернета
}

void processFile(string filename, int K) {

    ifstream testFile(filename);
    if (!testFile) {
        cout << "Ошибка: файл не существует!" << endl;
        return;
    }
    testFile.close();

    if (isFileEmpty(filename)) {
        cout << "Ошибка: файл пуст!" << endl;
        return;
    }
    

    ifstream inFile(filename);

    int lineCount = 0;
    string tempLine;

    // Читаем файл построчно
    while (getline(inFile, tempLine)) {
        lineCount++;
    }
    inFile.close();

    string* lines = new string[lineCount + 1];

    inFile.open(filename);
    for (int i = 0; i < lineCount; ++i) {
        getline(inFile, lines[i]);
    }
    inFile.close();

    if (K <= lineCount) {
        for (int i = lineCount; i >= K; --i) { // Сдвиг строк для выделения места под пустую строку
            lines[i] = lines[i - 1];
        }
        lines[K - 1] = "";
        lineCount++;
    }
    //Запись в файл
    if (K <= lineCount) {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Ошибка записи в файл!" << endl;
            delete[] lines;
            return;
        }

        for (int i = 0; i < lineCount; ++i) {
            outFile << lines[i] << endl;
        }
        outFile.close();

        delete[] lines;
        cout << "Файл успешно обработан." << endl;
    }
    else {
        delete[] lines;
        cout << "Файл без изменений." << endl;
    }
}