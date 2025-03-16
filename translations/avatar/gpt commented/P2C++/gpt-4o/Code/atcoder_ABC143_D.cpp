#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read input values: first value is n, followed by n integers
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }

    // Sort the list of integers
    sort(l.begin(), l.end());

    // Initialize the answer variable to count valid triplets
    long long ans = 0;

    // Iterate through each pair of elements in the sorted list
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int a = l[i];  // First element of the pair
            int b = l[j];  // Second element of the pair
            
            // Find the index where a + b would fit in the sorted list
            int right = lower_bound(l.begin(), l.end(), a + b) - l.begin();
            
            // Find the index where max(a - b, b - a) would fit in the sorted list
            int left = upper_bound(l.begin(), l.end(), max(a - b, b - a)) - l.begin();
            
            // Calculate the number of valid third elements that can form a triplet
            long long tmp = max(0LL, right - left);
            
            // Adjust the count if the indices i or j are within the range of valid third elements
            if (left <= i && i < right) {
                tmp--;  // Exclude the first element if it's counted
            }
            if (left <= j && j < right) {
                tmp--;  // Exclude the second element if it's counted
            }
            
            // Add the number of valid triplets formed with the current pair (i, j)
            ans += tmp;
        }
    }

    // Since each triplet is counted three times, divide the final answer by 3
    cout << ans / 3 << endl;

    return 0;
}

// <END-OF-CODE>
