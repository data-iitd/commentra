#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// N: [1, 2e5]
// len(S) = N
// P: [2, 10000], prime

int checkSubNumbers(int N, int P, const string& S) {
    switch (P) {
        case 2:
        case 5:
            return checkTwoOrFive(N, P, S);
        default:
            return checkNotTwoNorFive(N, P, S);
    }
}

int checkTwoOrFive(int N, int P, const string& S) {
    int answer = 0;
    for (int i = N - 1; i >= 0; --i) {
        int n = S[i] - '0';
        if (n % P == 0) {
            answer += i + 1;
        }
    }
    return answer;
}

int checkNotTwoNorFive(int N, int P, const string& S) {
    vector<int> remainderLookup(P, 0);
    int multiplier = 1;
    int answer = 0;
    int remainder = 0;
    int prevRemainder = -1;
    for (int i = N - 1; i >= 0; --i) {
        int digit = S[i] - '0';
        if (prevRemainder == -1) {
            remainder = digit % P;
        } else {
            remainder = ((multiplier * digit) % P + prevRemainder) % P;
        }
        if (remainder == 0) {
            answer++;
        }
        answer += remainderLookup[remainder];
        remainderLookup[remainder]++;
        prevRemainder = remainder;
        multiplier = (multiplier * 10) % P;
    }
    return answer;
}

int main() {
    int N, P;
    string S;
    cin >> N >> P >> S;
    int answer = checkSubNumbers(N, P, S);
    cout << answer << endl;
    return 0;
}

