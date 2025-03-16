#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Scanner {
public:
    Scanner() : r(cin.rdbuf()) {}

    string next() {
        string result;
        while ((!isdigit(peek())) && (peek() != '-')) {
            get();
        }
        while (isdigit(peek()) || peek() == '-') {
            result += get();
        }
        return result;
    }

    int nextInt() {
        return stoi(next());
    }

    vector<int> nextIntArray() {
        vector<int> result;
        string line = nextLine();
        stringstream ss(line);
        int num;
        while (ss >> num) {
            result.push_back(num);
        }
        return result;
    }

private:
    streambuf* r;

    char get() {
        char ch;
        r->get(ch);
        return ch;
    }

    char peek() {
        char ch;
        r->peek(ch);
        return ch;
    }

    string nextLine() {
        string line;
        getline(cin, line);
        return line;
    }
};

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    Scanner sc;
    int H = sc.nextInt();
    int W = sc.nextInt();
    int N = sc.nextInt();

    int A = max(H, W);

    cout << (N + A - 1) / A << endl;

    return 0;
}
