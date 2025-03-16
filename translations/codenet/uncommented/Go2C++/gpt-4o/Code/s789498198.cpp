#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

class Scanner {
public:
    Scanner() {
        buffer.reserve(100);
    }

    void readLine() {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string word;
        buffer.clear();
        while (ss >> word) {
            buffer.push_back(word);
        }
        cur = 0;
    }

    string next() {
        if (cur == buffer.size()) {
            readLine();
        }
        return buffer[cur++];
    }

    int nextInt() {
        return stoi(next());
    }

    vector<int> nextInts() {
        readLine();
        vector<int> res;
        for (const auto& str : buffer) {
            res.push_back(stoi(str));
        }
        return res;
    }

private:
    vector<string> buffer;
    size_t cur = 0;
};

int main() {
    Scanner sc;
    vector<int> AB = sc.nextInts();
    int A = AB[0];
    int B = AB[1];

    if ((A + B) % 2 == 0) {
        cout << (A + B) / 2 << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}

// <END-OF-CODE>
