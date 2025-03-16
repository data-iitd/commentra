
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaring static variables for input and output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Declaring variables for input and output
    int K;

    // Reading the input value of K
    cin >> K;

    // Checking if K is even or multiple of 5, returning -1 if true
    if (K % 2 == 0 || K % 5 == 0) return -1;

    // If K is multiple of 7, dividing it by 7 and multiplying it by 9
    if (K % 7 == 0) K /= 7;
    K *= 9;

    // Initializing the answer variable and the remainder variable
    int ans = 1, remainder = 10 % K;

    // Using a while loop to find the answer
    while (remainder!= 1) {
        ans++; // Incrementing the answer variable
        remainder = remainder * 10 % K; // Updating the remainder variable
    }

    // Returning the answer
    return ans;
}

