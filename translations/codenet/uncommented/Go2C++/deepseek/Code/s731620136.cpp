#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

class Scanner {
public:
    Scanner(std::istream& is) : is(is) {}

    std::string nextStr() {
        std::string line;
        std::getline(is, line);
        return line;
    }

    int nextInt() {
        std::string line = nextStr();
        return std::stoi(line);
    }

    double nextFloat() {
        std::string line = nextStr();
        return std::stod(line);
    }

    std::vector<char> nextRuneSlice() {
        std::string line = nextStr();
        return std::vector<char>(line.begin(), line.end());
    }

    std::vector<int> nextIntSlice(int n) {
        std::vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    std::vector<double> nextFloatSlice(int n) {
        std::vector<double> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextFloat();
        }
        return res;
    }

private:
    std::istream& is;
};

int run(std::istream& input, std::ostream& output) {
    Scanner sc(input);
    int N = sc.nextInt();
    std::string S = sc.nextStr();

    if (N == 0) {
        return 0;
    }

    if (N < 4) {
        output << 0 << std::endl;
        return 0;
    }

    int nr = 0, nb = 0, ng = 0;
    for (char c : S) {
        if (c == 'R') {
            nr++;
        } else if (c == 'B') {
            nb++;
        } else if (c == 'G') {
            ng++;
        }
    }

    int same = 0;
    for (int a = 1; a < N; a++) {
        int i = 0;
        int j = a;
        int k = 2 * a;
        if (k >= N) {
            break;
        }
        while (k < N) {
            if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
                same++;
            }
            i++;
            j++;
            k++;
        }
    }

    int tot = nr * nb * ng;
    output << (tot - same) << std::endl;

    return 0;
}

int main() {
    run(std::cin, std::cout);
    return 0;
}
