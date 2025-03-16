#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class FastScanner {
public:
    FastScanner() : buffer(istream_iterator<string>(cin)), end(istream_iterator<string>()) {}

    string next() {
        if (buffer == end || buffer->empty()) {
            *buffer = string();
            getline(cin, *buffer);
        }
        string result = *buffer;
        ++buffer;
        return result;
    }

    int nextInt() {
        return stoi(next());
    }

    int64_t nextInt64() {
        return stoll(next());
    }

private:
    istream_iterator<string> buffer, end;
};

int main() {
    FastScanner fsc;
    int A = fsc.nextInt();
    int B = fsc.nextInt();
    int C = fsc.nextInt();
    if (B - A == C - B) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

