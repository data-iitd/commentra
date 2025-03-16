#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <exception>

class InputReader {
private:
    std::istream& in;
    std::stringstream ss;
    std::string token;

public:
    InputReader(std::istream& inputStream) : in(inputStream) {
        token.clear();
    }

    std::string nextString() {
        while (!ss.good() && in) {
            std::string line;
            std::getline(in, line);
            ss.str(line);
            ss.clear();
        }
        std::getline(ss, token, ' ');
        return token;
    }

    int nextInt() {
        return std::stoi(nextString());
    }

    std::vector<int> nextIntArray(int n) {
        std::vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }
};

class TaskD {
public:
    void solve(int testNumber, InputReader& in, std::ostream& out) {
        int n = in.nextInt();
        int m = in.nextInt();

        std::vector<int> a = in.nextIntArray(n);
        std::unordered_map<int, int> dp;

        long long ans = 0;
        int base = 0;

        for (int i = 0; i < n; i++) {
            base = (base - a[i] % m + m) % m;
            dp[(base + a[i] % m) % m]++;
            ans += dp[base];
        }

        out << ans << std::endl;
    }
};

int main() {
    InputReader in(std::cin);
    TaskD solver;
    solver.solve(1, in, std::cout);
    return 0;
}

