#include <iostream>
#include <unordered_map>

using namespace std;

void usage() {
    cout << "Enter length in format \"number measure\", for instance \"1 m\"\n"
        "Supported measures: mm cm dm m km\n";
}

int main() {
    unordered_map<string, int> measures
        = {{"mm", 1}, {"cm", 10}, {"dm", 1e2}, {"m", 1e3}, {"km", 1e6}};
    int n;
    string m;
    cin >> n >> m;
    int mm = n * measures[m];

    string best = "mm";
    for (const auto& [measure, val] : measures) {
        if (mm >= val &&
            best.size() + mm / measures[best] > measure.size() + mm / val) {
            best = measure;
        }
    }

    cout << mm / measures[best] << ' ' << best << '\n';
}
