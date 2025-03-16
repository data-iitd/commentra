
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class InputScanner {
private:
    istream *stream;
    vector<string> tokens;
    int current;

public:
    InputScanner(istream &stream) : stream(&stream), current(0) {}

    void nextToken() {
        string token;
        *stream >> token;
        tokens.push_back(token);
    }

    string nextStr() {
        if (current >= tokens.size()) {
            nextToken();
        }
        return tokens[current++];
    }

    int nextInt() {
        return atoi(nextStr().c_str());
    }

    unsigned long long nextUInt64() {
        return atoll(nextStr().c_str());
    }
};

int checkSubNumbers(int N, int P, string S) {
    if (P == 2 || P == 5) {
        return checkTwoOrFive(N, P, S);
    } else {
        return checkNotTwoNorFive(N, P, S);
    }
}

int checkTwoOrFive(int N, int P, string S) {
    int answer = 0;
    int n;
    for (int i = N - 1; i >= 0; i--) {
        n = atoi(S.substr(i, 1).c_str());
        if (n % P == 0) {
            answer += i + 1;
        }
    }
    return answer;
}

int checkNotTwoNorFive(int N, int P, string S) {
    int multiplier = 1;
    int answer = 0;
    vector<int> remainderLookup(P);
    int prevRemaider = -1;
    int digit, remainder, count;
    for (int i = N - 1; i >= 0; i--) {
        digit = atoi(S.substr(i, 1).c_str());
        if (prevRemaider == -1) {
            remainder = digit % P;
        } else {
            remainder = (((multiplier * digit) % P) + prevRemaider) % P;
        }
        if (remainder == 0) {
            answer++;
        }
        count = remainderLookup[remainder];
        answer += count;
        count++;
        remainderLookup[remainder] = count;
        prevRemaider = remainder;
        multiplier = (multiplier * 10) % P;
    }
    return answer;
}

int main() {
    InputScanner scanner(cin);
    int N = scanner.nextInt();
    int P = scanner.nextInt();
    string S = scanner.nextStr();
    int answer = checkSubNumbers(N, P, S);
    cout << answer << endl;
    return 0;
}

