
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <map>
#include <string>
using namespace std;

#define MOD 1000000007LL

typedef long long ll;

int N;
map<string, ll> memo[100001];
string tokens[4] = {"A", "C", "G", "T"};

ll dfs(int current, string last3) {
    if (memo[current].find(last3)!= memo[current].end()) {
        return memo[current][last3];
    }
    if (current == N) {
        return 1;
    }
    ll result = 0;
    for (int i = 0; i < 4; i++) {
        string nextLast3 = last3.substr(1, 3) + tokens[i];
        if (nextLast3.find("AGC") == string::npos) {
            result = (result + dfs(current + 1, nextLast3)) % MOD;
        }
    }
    memo[current][last3] = result;
    return result;
}

int main() {
    scanf("%d", &N);
    printf("%lld\n", dfs(0, "TTT"));
    return 0;
}
//END-OF-CODE