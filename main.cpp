#include <iostream>
#include <fstream>
#include <format>

using namespace std;

int main() {
    int pointer = 50;
    int counter = 0;

    ifstream file("../sequence.txt");
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            int num = stoi(line.substr(1, line.length()));
            if (num > 99) {
                string str_num = format("{}", num);
                num = stoi(str_num.substr(1, line.length()));
            }
            if (line[0] == 'R') {
                if (pointer + num > 99) {
                    pointer = pointer + num - 100;
                } else {
                    pointer = pointer + num;
                }
            } else {
                if (pointer - num < 0) {
                    pointer = pointer - num + 100;
                } else {
                    pointer = pointer - num;
                }
            }

            //cout << pointer << endl;

            if (pointer == 0) {
                counter++;
            }
        }
        file.close();
    } else {
        cerr << "Unable to open file" << endl;
    }

    cout << "Rezultat je : " << counter << endl;
    return 0;
}
