//
// Created by Matteo Lovrić on 03.12.2025..
//

//find ranges

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ifstream file("sequence_02.txt");
    string line;

    vector<string> ranges;

    if (file.is_open()) {
        while (getline(file, line)) {
            int n = line.length();
            while (line.find(",") != line.npos) {
                string range = line.substr(0, line.find(","));
                ranges.push_back(range);
                line = line.erase(0, line.find(",") + 1);
            }
            ranges.push_back(line);
        }

        file.close();
    } else {
        cerr << "Unable to open file." << endl;
    }

    long int sum = 0;
    for (string range: ranges) {
        string range_begin = range.substr(0, range.find("-"));
        string range_end = range.erase(0, range.find("-") + 1);

        long int r_begin = stol(range_begin);
        long int r_end = stol(range_end);


        for (long int i = r_begin; i <= r_end; i++) {
            string num_str = to_string(i);
            if (num_str.length() <= 2) {
                if (num_str[0] == num_str[1]) {
                    long int n = stol(num_str);
                    cout << n << endl;
                    sum += n;
                }
            } else {
                long int mid_pos = num_str.length() / 2;
                string first = num_str.substr(0, mid_pos);
                string last = num_str.substr(mid_pos, num_str.length());

                if (first == last) {
                    long int n = stol(num_str);
                    cout << n << endl;
                    sum += n;
                }
            }
        }
    }

    cout << sum << endl;
}
