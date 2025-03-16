#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <vector>

#define MOD 1000000007L

using namespace std;

class Main {
    int N;
    long long MOD;
    char *TOKENS;
    map<string, long long> *memo;

public:
    Main() {
        scanf("%d", &N);
        MOD = 1000000007L;
        TOKENS = (char *)malloc(4 * sizeof(char));
        TOKENS[0] = 'A';
        TOKENS[1] = 'C';
        TOKENS[2] = 'G';
        TOKENS[3] = 'T';
        memo = (map<string, long long> *)malloc((N + 1) * sizeof(map<string, long long>));
        for (int i = 0; i < N + 1; ++i) {
            memo[i] = map<string, long long>();
        }
    }

    long long calc() {
        return dfs(0, "TTT");
    }

    bool isOK(char *last4) {
        if (strstr(last4, "AGC") != NULL) {
            return false;
        }
        for (int i = 0; i < 3; ++i) {
            char vals[5];
            strcpy(vals, last4);
            vals[i] = last4[i + 1];
            vals[i + 1] = last4[i];
            if (strstr(vals, "AGC") != NULL) {
                return false;
            }
        }
        return true;
    }

    long long dfs(int current, char *last3) {
        if (memo[current].find(last3) != memo[current].end()) {
            return memo[current][last3];
        }
        if (current == N) {
            return 1;
        }
        long long result = 0;
        for (int i = 0; i < 4; ++i) {
            char next[4];
            strcpy(next, last3);
            next[2] = TOKENS[i];
            if (isOK(next)) {
                result = (result + dfs(current + 1, next + 1)) % MOD;
            }
        }
        memo[current][last3] = result;
        return result;
    }

    int main() {
        Main ins = Main();
        printf("%lld\n", ins.calc());
        return 0;
    }
};

