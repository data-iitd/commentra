#include <iostream>
#include <string>
#include <vector>
#include <numeric> // for std::gcd
using namespace std;

string rs() {
    string line;
    getline(cin, line);
    return line.rstrip();
}

int ri() {
    return stoi(rs());
}

vector<string> rs_(const string& s) {
    vector<string> result;
    string word;
    for (char c : s) {
        if (c == ' ') {
            if (!word.empty()) {
                result.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        result.push_back(word);
    }
    return result;
}

vector<int> ri_(const string& s) {
    vector<int> result;
    vector<string> words = rs_(s);
    for (const string& word : words) {
        result.push_back(stoi(word));
    }
    return result;
}

int main() {
    int N = ri();
    long long ans = 0;
    for (int i = 1; i <= N; ++i) {
        int div = N / i;
        ans += i * div * (div + 1) / 2;
    }
    cout << ans << endl;
    return 0;
}
