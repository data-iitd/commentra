#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

class Scanner {
public:
    Scanner() : buffer(0), index(0) {}

    void readln() {
        string line;
        getline(cin, line);
        istringstream iss(line);
        string word;
        buffer.clear();
        while (iss >> word) {
            buffer.push_back(word);
        }
        index = 0;
    }

    bool isFull() const {
        return index == buffer.size();
    }

    void resetIndex() {
        index = 0;
    }

    string next() {
        if (index == 0) {
            readln();
        }
        string res = buffer[index];
        index++;
        if (isFull()) {
            resetIndex();
        }
        return res;
    }

    vector<string> nexts() {
        readln();
        resetIndex();
        return buffer;
    }

    int nextInt() {
        return stoi(next());
    }

    vector<int> nextInts() {
        readln();
        vector<int> res(buffer.size());
        for (size_t i = 0; i < buffer.size(); ++i) {
            res[i] = stoi(buffer[i]);
        }
        resetIndex();
        return res;
    }

    double nextFloat() {
        return stod(next());
    }

    vector<double> nextFloats() {
        readln();
        vector<double> res(buffer.size());
        for (size_t i = 0; i < buffer.size(); ++i) {
            res[i] = stod(buffer[i]);
        }
        resetIndex();
        return res;
    }

    int digits(int x) const {
        return to_string(x).length();
    }

    int powInt(int x, int p) const {
        int result = 1;
        for (int i = 0; i < p; ++i) {
            result *= x;
        }
        return result;
    }

    int max(int x, int y) const {
        return max(x, y);
    }

    int min(int x, int y) const {
        return min(x, y);
    }

    int abs(int x) const {
        return abs(x);
    }

private:
    vector<string> buffer;
    size_t index;
};

Scanner sc;

int main() {
    // Read two integers from input
    vector<int> AB = sc.nextInts();
    int A = AB[0];
    int B = AB[1];

    // Check if the sum of A and B is even
    if ((A + B) % 2 == 0) {
        // If even, print the average
        cout << (A + B) / 2 << endl;
        return 0;
    }
    // If odd, print "IMPOSSIBLE"
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

