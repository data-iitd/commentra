#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    auto R = []() {
        vector<int> result;
        string line;
        getline(cin, line);
        stringstream ss(line);
        int number;
        while (ss >> number) {
            result.push_back(number);
        }
        return result;
    };

    vector<int> input = R();
    int n = input[0], m = input[1], s = input[2], f = input[3];

    int d;
    char c;
    if (s < f) {
        d = 1;
        c = 'R';
    } else {
        d = -1;
        c = 'L';
    }

    string res = "";
    int i = 1;
    int j = s;
    input = R();
    int t = input[0], l = input[1], r = input[2];
    int k = 1;

    while (j != f) {
        if (i > t && k < m) {
            input = R();
            t = input[0];
            l = input[1];
            r = input[2];
            k++;
        }
        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
            res += 'X';
        } else {
            res += c;
            j += d;
        }
        i++;
    }

    cout << res << endl;

    return 0;
}

// <END-OF-CODE>
