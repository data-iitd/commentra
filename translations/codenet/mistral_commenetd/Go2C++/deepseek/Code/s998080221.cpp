#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

class Reader {
public:
    Reader() : buffer(std::make_unique<std::string>()), index(0) {}

    void readLine() {
        std::getline(std::cin, *buffer);
        index = 0;
    }

    std::string next() {
        readLine();
        size_t from = index;
        while (index < buffer->size() && (*buffer)[index] != ' ') {
            index++;
        }
        std::string token = buffer->substr(from, index - from);
        index++;
        return token;
    }

    int nextInt() {
        return std::stoi(next());
    }

    std::string nextLine() {
        readLine();
        return *buffer;
    }

private:
    std::unique_ptr<std::string> buffer;
    size_t index;
};

Reader reader;

int nextInt() {
    return reader.nextInt();
}

long long nextInt64() {
    return std::stoll(reader.next());
}

std::string nextLine() {
    return reader.nextLine();
}

void out(const std::string& s) {
    std::cout << s << std::endl;
}

long long max64(long long x, long long y) {
    return x > y ? x : y;
}

int max(int x, int y) {
    return x > y ? x : y;
}

long long min64(long long x, long long y) {
    return x < y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

long long abs64(long long x) {
    return x < 0 ? -x : x;
}

int abs(int x) {
    return x < 0 ? -x : x;
}

std::string joinInt64s(const std::vector<long long>& a, const std::string& sep) {
    std::vector<std::string> b(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        b[i] = std::to_string(a[i]);
    }
    return joinStrings(b, sep);
}

std::string joinStrings(const std::vector<std::string>& a, const std::string& sep) {
    std::string result;
    for (size_t i = 0; i < a.size(); ++i) {
        if (i > 0) {
            result += sep;
        }
        result += a[i];
    }
    return result;
}

long long divUp64(long long x, long long y) {
    return (x + y - 1) / y;
}

int divUp(int x, int y) {
    return int(divUp64(x, y));
}

long long gcd64(long long x, long long y) {
    while (y != 0) {
        long long temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int gcd(int x, int y) {
    return int(gcd64(x, y));
}

long long lcm64(long long x, long long y) {
    return x * y / gcd64(x, y);
}

int lcm(int x, int y) {
    return int(lcm64(x, y));
}

long long pow64(long long x, long long y) {
    return static_cast<long long>(std::pow(x, y));
}

int pow(int x, int y) {
    return int(pow64(x, y));
}

void solve() {
    int N = nextInt();
    int K = nextInt();
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = nextInt();
    }
    long long maxProfit = 0;
    int maxCnt = 0;
    int maxA = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        int profit = std::max(0, maxA - A[i]);
        if (maxProfit < profit) {
            maxProfit = profit;
            maxCnt = 1;
        } else if (maxProfit == profit) {
            maxCnt++;
        }
        maxA = std::max(maxA, A[i]);
    }
    out(std::to_string(maxCnt));
}

int main() {
    solve();
    return 0;
}
