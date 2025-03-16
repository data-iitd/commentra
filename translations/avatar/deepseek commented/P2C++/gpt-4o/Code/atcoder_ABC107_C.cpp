#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;  // Reading N and K from input
    vector<int> lst(N);  // Vector to store the list of integers
    for (int i = 0; i < N; i++) {
        cin >> lst[i];  // Reading the list of integers
    }

    vector<int> lst_p;  // Vector to store positive numbers
    vector<int> lst_m;  // Vector to store negative numbers

    // Separating positive and negative numbers
    for (int i = 0; i < N; i++) {
        if (lst[i] == 0) {
            K--;  // Decrement K if the number is 0
        }
        if (lst[i] > 0) {
            lst_p.push_back(lst[i]);  // Add positive numbers to lst_p
        } else if (lst[i] < 0) {
            lst_m.push_back(lst[i]);  // Add negative numbers to lst_m
        }
    }

    // Initialization of pointers and variables
    int lastx = lst_p.size();  // Last index of lst_p
    int lasty = lst_m.size();  // Last index of lst_m

    // Function to check the minimum possible value
    auto check = [&](int k) {
        int ans = 1e9;  // Initialize answer with a large number
        for (int j = 0; j <= k; j++) {
            if (j > lastx || k - j > lasty) {  // Check if indices are out of bounds
                continue;
            }
            int p = (j == 0) ? 0 : lst_p[j - 1];  // Get the (j-1)th positive number
            int m = (k - j == 0) ? 0 : lst_m[lasty - (k - j)];  // Get the (lasty - (k - j))th negative number
            ans = min(ans, 2 * p + abs(m));  // Calculate the minimum value
            ans = min(ans, p + 2 * abs(m));  // Calculate the minimum value
        }
        return ans;
    };

    // Output the result of the check function with K as the argument
    cout << check(K) << endl;

    return 0;
}

// <END-OF-CODE>
