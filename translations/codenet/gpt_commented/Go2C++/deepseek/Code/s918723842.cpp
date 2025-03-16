#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Scanner {
public:
    Scanner() : buffer(istream_iterator<string>(cin), istream_iterator<string>()) {}
    int NextInt() { return stoi(Next()); }
    string Next() {
        if (index >= buffer.size()) {
            string line;
            getline(cin, line);
            buffer = vector<string>({istream_iterator<string>(istringstream(line)), istream_iterator<string>()});
            index = 0;
        }
        return buffer[index++];
    }
    vector<int> NextIntArray() {
        vector<int> result;
        string s = Next();
        istringstream iss(s);
        int num;
        while (iss >> num) {
            result.push_back(num);
        }
        return result;
    }
private:
    vector<string> buffer;
    size_t index = 0;
};

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    Scanner sc;
    int H = sc.NextInt(), W = sc.NextInt(), N = sc.NextInt();
    int A = max(H, W);
    cout << (N + A - 1) / A << endl;
}

