#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Input {
public:
    string NextLine() {
        string line;
        getline(cin, line);
        return line;
    }

    int NextInt() {
        return stoi(NextLine());
    }

    vector<int64_t> NextIntArray() {
        string line = NextLine();
        vector<int64_t> result;
        stringstream ss(line);
        int64_t number;
        while (ss >> number) {
            result.push_back(number);
        }
        return result;
    }
};

int main() {
    Input input;
    int n = input.NextInt();
    vector<int64_t> s = input.NextIntArray();
    vector<bool> u(n, false);
    int64_t m = 0, f;

    for (int c = 1; c < n - 1; c++) {
        f = 0;
        for (int k = 0; c < n - 1 - k * c; k++) {
            u[k * c] = true;
            if (u[n - 1 - k * c]) break;
            f += s[n - 1 - k * c] + s[k * c];
            if (m < f) m = f;
        }
        for (int k = 0; k * c < n - 1; k++) {
            u[k * c] = false;
        }
    }
    cout << m << endl;
    return 0;
}

// <END-OF-CODE>
