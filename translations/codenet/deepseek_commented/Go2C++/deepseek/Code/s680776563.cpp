#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// FastScanner struct: Efficiently reads input.
class FastScanner {
public:
    FastScanner() : buffer(istream_iterator<string>(cin), istream_iterator<string>()) {}

    int NextInt() {
        return stoi(buffer.front());
        buffer.erase(buffer.begin());
    }

    string Next() {
        string result = buffer.front();
        buffer.erase(buffer.begin());
        return result;
    }

    string NextLine() {
        string line;
        getline(cin, line);
        return line;
    }

private:
    vector<string> buffer;
};

// Main function: Entry point of the program.
// Initializes a FastScanner, reads three integers A, B, and C,
// and checks if the difference between consecutive integers is the same.
// If the difference is the same, it prints "YES"; otherwise, it prints "NO".
int main() {
    FastScanner fsc;
    int A = fsc.NextInt();
    int B = fsc.NextInt();
    int C = fsc.NextInt();
    if (B - A == C - B) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

