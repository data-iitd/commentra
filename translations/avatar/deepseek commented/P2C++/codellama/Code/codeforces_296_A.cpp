
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool possible = true;
    vector<string> m = split(s, ' ');

    for (int i = 0; i < m.size(); i++) {
        if (count(m.begin(), m.end(), m[i]) >= n / 2 + 1) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

vector<string> split(string s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream stream(s);

    while (getline(stream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

int count(vector<string>::iterator begin, vector<string>::iterator end, string s) {
    int count = 0;

    for (vector<string>::iterator it = begin; it != end; it++) {
        if (*it == s) {
            count++;
        }
    }

    return count;
}

