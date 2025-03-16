

#include <bits/stdc++.h>

using namespace std;

int main() {
    // Read the value of N
    long long N;
    cin >> N;

    // Initialize min to 0 and find the minimum of the first five inputs
    long long min = 0;
    for (int i = 0; i < 5; i++) {
        if (i == 0)
            min = cin.nextInt();
        else
            min = min < cin.nextInt()? min : cin.nextInt();
    }

    // Calculate the result and print it
    cout << (long long)ceil((double)N / min) + 4 << endl;

    return 0;
}

// Overloaded print methods to handle different data types
void p(string ans) {
    cout << ans << endl;
}

void p(int ans) {
    cout << ans << endl;
}

void p() {
    cout << endl;
}

void p(long long ans) {
    cout << ans << endl;
}

void p(double ans) {
    cout << ans << endl;
}

// End of code
