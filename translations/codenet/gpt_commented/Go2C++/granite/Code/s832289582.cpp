
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int checkSubNumbers(int N, int P, string S) {
    switch (P) {
        case 2:
        case 5:
            return checkTwoOrFive(N, P, S);
        default:
            return checkNotTwoNorFive(N, P, S);
    }
}

int checkTwoOrFive(int N, int P, string S) {
    int answer = 0;
    int n = 0;

    for (int i = N - 1; i >= 0; i--) {
        n = stoi(S.substr(i, 1));
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
    int digit = 0;
    int remainder = 0;
    int count = 0;

    for (int i = N - 1; i >= 0; i--) {
        digit = S[i] - '0';
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
    int N, P;
    string S;
    cin >> N >> P >> S;
    cout << checkSubNumbers(N, P, S) << endl;
    return 0;
}

