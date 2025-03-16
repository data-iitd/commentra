#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a < b) ? b : a;
}

// Main function
int main() {
    int A, B;
    cin >> A >> B;

    int mx = max(A + B, A - B);
    mx = max(mx, A * B);
    cout << mx << endl;

    return 0;
}

// Scanner class for reading input
class Scanner {
public:
    Scanner() {
        buffer.reserve(1000);
    }

    string Next() {
        pre();
        size_t start = p;
        while (p < buffer.size() && buffer[p] != ' ') {
            p++;
        }
        string result = buffer.substr(start, p - start);
        p++;
        return result;
    }

    int NextInt() {
        return stoi(Next());
    }

    void readLine() {
        buffer.clear();
        string line;
        getline(cin, line);
        buffer = line;
        p = 0;
    }

private:
    string buffer;
    size_t p = 0;

    void pre() {
        if (p >= buffer.size()) {
            readLine();
            p = 0;
        }
    }
};

// Example usage of Scanner class (not part of the original functionality)
void exampleUsage() {
    Scanner sc;
    int num = sc.NextInt();
    cout << "Read integer: " << num << endl;
}

