#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Function to check if any subnumber of given string S is divisible by prime number P
int checkSubNumbers(int N, int P, const string& S) {
    // Switch statement to check if P is equal to 2 or 5
    switch (P) {
        case 2:
        case 5:
            return checkTwoOrFive(N, P, S);
        default:
            return checkNotTwoNorFive(N, P, S);
    }
}

// Function to check if any subnumber of given string S is divisible by prime number P equal to 2 or 5
int checkTwoOrFive(int N, int P, const string& S) {
    int answer = 0;
    int n;
    // Iterate through the string S from the last character to the first character
    for (int i = N - 1; i >= 0; i--) {
        // Convert the substring from i to i+1 to an integer n
        n = S[i] - '0';
        // If n is divisible by P, add its index to the answer variable
        if (n % P == 0) {
            answer += i + 1;
        }
    }
    return answer;
}

// Function to check if any subnumber of given string S is divisible by prime number P which is not equal to 2 or 5
int checkNotTwoNorFive(int N, int P, const string& S) {
    int multiplier = 1;
    int answer = 0;
    vector<int> remainderLookup(P, 0);
    int prevRemaider = -1;
    // Iterate through the string S from the last character to the first character
    for (int i = N - 1; i >= 0; i--) {
        // Get the digit from the string S at the current index i
        int digit = S[i] - '0';
        // If prevRemaider is equal to -1, get the remainder of the first digit by dividing it by P
        if (prevRemaider == -1) {
            prevRemaider = digit % P;
        } else {
            // Otherwise, get the remainder of the current digit multiplied by multiplier and added to the previous remainder, then get the remainder of the result by dividing it by P
            int remainder = (((multiplier * digit) % P) + prevRemaider) % P;
            // If the remainder is equal to 0, add 1 to the answer variable
            if (remainder == 0) {
                answer++;
            }
            // Get the count of the current remainder from the slice remainderLookup
            int count = remainderLookup[remainder];
            // Add the count to the answer variable
            answer += count;
            // Update the slice remainderLookup with the new count of the current remainder
            remainderLookup[remainder]++;
        }
        // Update the multiplier as multiplier * 10 % P
        prevRemaider = remainder;
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

