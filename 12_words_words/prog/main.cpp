#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void usage() {
    cout << "Enter the initial word, list of new words (one word on each line),"
         " then enter an empty line.\n";
}

int char2int(char ch) {
    if (ch < 'a')
        return ch - 'A' + ('z' - 'a') + 1;
    return ch - 'a';
}

int main() {
    usage();

    int initial_cntr[46];
    fill(initial_cntr, initial_cntr + 46, 0);
    string initial;
    getline(cin, initial);
    for (char ch : initial) {
        ++initial_cntr[char2int(ch)];
    }

    vector<string> wrong;
    string s;
    getline(cin, s);
    while (!s.empty()) {
        int s_cntr[46];
        fill(s_cntr, s_cntr + 46, 0);
        for (char ch : s) {
            ++s_cntr[char2int(ch)];
        }
        for (int i = 0; i < 46; ++i) {
            if (s_cntr[i] > initial_cntr[i]) {
                wrong.push_back(s);
            }
        }

        getline(cin, s);
    }

    for (const string &str : wrong) {
        cout << str << '\n';
    }
}
