#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int nextInt() {
    int n;
    cin >> n;
    return n;
}

vector<string> nextStringArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<string> result;
    string word;
    while (ss >> word) {
        result.push_back(word);
    }
    return result;
}

int nextInt(const vector<string>& words, int& index) {
    return stoi(words[index++]);
}

vector<int> nextIntArray(const vector<string>& words, int& index) {
    vector<int> result;
    while (index < words.size()) {
        result.push_back(stoi(words[index++]));
    }
    return result;
}

int min(int i, int j) {
    return i < j ? i : j;
}

int main() {
    int n = nextInt();
    int rt = static_cast<int>(sqrt(n));
    int minf = 100;

    for (int i = 1; i <= rt + 1; ++i) {
        if (n % i == 0) {
            int b = n / i;
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ++ndigit;
            }
            minf = min(minf, ndigit);
        }
    }

    cout << minf << endl;
    return 0;
}
