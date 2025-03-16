#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function declarations
int checkSubNumbers(int N, int P, const string& S);
int checkTwoOrFive(int N, int P, const string& S);
int checkNotTwoNorFive(int N, int P, const string& S);

int main() {
    int N, P;
    string S;

    // Input reading
    cin >> N >> P >> S;

    int answer = checkSubNumbers(N, P, S);
    cout << answer << endl;

    return 0;
}

int checkSubNumbers(int N, int P, const string& S) {
    if (P == 2 || P == 5) {
        return checkTwoOrFive(N, P, S);
    } else {
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
    int multiplier = 1; // 10^i % P
    int answer = 0;
    vector<int> remainderLookup(P, 0);
    int prevRemainder = -1;
    int digit, remainder, count;

    for (int i = N - 1; i >= 0; --i) {
        digit = S[i] - '0';
        if (prevRemainder == -1) { // first digit
            remainder = digit % P;
        } else {
            remainder = ((multiplier * digit) % P + prevRemainder) % P;
        }
        if (remainder == 0) {
            answer++;
        }
        count = remainderLookup[remainder];
        answer += count;
        count++;
        remainderLookup[remainder] = count;
        prevRemainder = remainder;
        multiplier = (multiplier * 10) % P;
    }
    return answer;
}

// <END-OF-CODE>
