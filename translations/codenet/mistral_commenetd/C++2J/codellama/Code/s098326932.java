#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
const ll INF = 1e18+1;

// Function to find the number with minimum ratio of digits to total number
ll f(ll N) {
    // Initialize a vector to store digits of the number
    vector<ll> a(20,0);
    ll d = 0; // Index to store the current digit position

    // Extract digits from N and store them in the vector 'a'
    while (N > 0) {
        a[d] = N % 10; // Store the current digit
        N /= 10; // Move to the next digit
        d++; // Increment the index
    }

    // Initialize minimum ratio and the result
    double m = 1e18;
    ll res = N;

    // Iterate through each digit position from 0 to the last digit position
    for (int i = 0; i <= d; i++) {
        // Initialize sum of digits before the current digit position
        ll bunsi = 0;
        // Initialize the sum of digits after the current digit position
        ll bunbo = 9 * i;

        // Calculate the sum of digits before the current digit position
        for (int j = d-1; j >= 0; j--) {
            // Update the sum of digits before the current digit position
            bunsi *= 10;
            if (j < i) bunsi += 9; // Add 9 for each digit before the current digit position
            else bunsi += a[j]; // Add the current digit

            // Update the sum of digits after the current digit position
            if (j >= i) bunbo += a[j];
        }

        // Calculate the ratio of digits before the current digit position to the sum of digits before and after the current digit position
        double frac = (double) bunsi / (double) bunbo;

        // Update the minimum ratio and the result if the current ratio is smaller than the previous minimum ratio
        if (frac < m) {
            m = frac;
            res = bunsi;
        }
    }

    // Return the number with the minimum ratio of digits to total number
    return res;
}

// Main function to read the input and print the output
int main() {
    // Read the number of test cases
    ll K;
    cin >> K;

    // Initialize the number with the minimum ratio of digits to total number
    ll N = f(1);

    // Print the answer for each test case
    for (ll i = 0; i < K; i++) {
        cout << N << endl;
        N = f(N+1);
    }
}

