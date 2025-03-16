#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// Determines the maximum of two integers.
int max(int a, int b) {
    return a > b ? a : b;
}

// Scanner struct to read input efficiently.
class Scanner {
public:
    Scanner(istream& is) : is_(is) {}

    // Reads the next token from the input buffer.
    string Next() {
        string token;
        is_ >> token;
        return token;
    }

    // Reads the next line from the input buffer.
    string NextLine() {
        string line;
        getline(is_, line);
        return line;
    }

    // Reads the next integer from the input buffer.
    int NextInt() {
        int value;
        is_ >> value;
        return value;
    }

    // Reads the next 64-bit integer from the input buffer.
    int64_t NextInt64() {
        int64_t value;
        is_ >> value;
        return value;
    }

    // Reads the next float from the input buffer.
    double NextFloat() {
        double value;
        is_ >> value;
        return value;
    }

    // Reads the next array of integers from the input buffer.
    vector<int> NextIntArray() {
        vector<int> array;
        string line = NextLine();
        stringstream ss(line);
        int value;
        while (ss >> value) {
            array.push_back(value);
        }
        return array;
    }

    // Reads the next array of 64-bit integers from the input buffer.
    vector<int64_t> NextInt64Array() {
        vector<int64_t> array;
        string line = NextLine();
        stringstream ss(line);
        int64_t value;
        while (ss >> value) {
            array.push_back(value);
        }
        return array;
    }

    // Reads the next map of integers from the input buffer.
    map<int, bool> NextMap() {
        map<int, bool> mp;
        string line = NextLine();
        stringstream ss(line);
        int value;
        while (ss >> value) {
            mp[value] = true;
        }
        return mp;
    }

private:
    istream& is_;
};

int main() {
    Scanner sc(cin);

    // Reads three integers H, W, and N from the standard input.
    int H = sc.NextInt();
    int W = sc.NextInt();
    int N = sc.NextInt();

    // Determines the maximum of H and W and assigns it to A.
    int A = max(H, W);

    // Calculates the result by dividing N by A and rounding up.
    // This is done by adding N-1 to the division result and then performing integer division by A.
    cout << (N + A - 1) / A << endl;

    return 0;
}
