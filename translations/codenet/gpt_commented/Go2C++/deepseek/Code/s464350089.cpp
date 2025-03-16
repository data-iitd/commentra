#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

const long long MOD = 1000000007;
const int IO_BUFFER_SIZE = 1 * 1024 * 1024;

class FastIO {
public:
    FastIO() {
        std::cin.sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cin.rdbuf()->pubsetbuf(new char[IO_BUFFER_SIZE], IO_BUFFER_SIZE);
    }
    ~FastIO() {
        delete[] std::cin.rdbuf()->pubptr();
    }
};

FastIO fastIO;

int nextInt() {
    int num;
    std::cin >> num;
    return num;
}

std::string next() {
    std::string str;
    std::cin >> str;
    return str;
}

int main() {
    int h = nextInt();
    int n = nextInt();
    long long a = 0;

    for (int i = 0; i < n; ++i) {
        a += nextInt();
    }

    if (h > a) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }

    return 0;
}
