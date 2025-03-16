/*
 * FileName:     the_number_of_inversions_fix
 * CreatedDate:  2020-06-05 16:25:10 +0900
 * LastModified: 2020-07-06 22:22:35 +0900
 */

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Function to merge two subarrays and count inversions
long long sort(vector<long long>& a, int left, int middle, int right) {
    vector<long long> l_arr(middle - left + 1), r_arr(right - middle);
    long long cnt = 0;
    
    // Copy elements into temporary arrays
    for (int i = 0; i < middle - left + 1; i++) l_arr[i] = a[left + i];
    for (int i = 0; i < right - middle; i++) r_arr[i] = a[middle + 1 + i];
    
    // Sentinel values to simplify merging
    l_arr[middle - left] = numeric_limits<long long>::max();
    r_arr[right - middle] = numeric_limits<long long>::max();
    
    int l = 0, r = 0;
    
    // Merge the two subarrays while counting inversions
    for (int i = 0; i < right - left; i++) {
        if (l_arr[l] <= r_arr[r]) {
            a[left + i] = l_arr[l++];
        } else {
            a[left + i] = r_arr[r++];
            cnt += middle - left + 1 - l; // Count inversions
        }
    }
    return cnt;
}

// Recursive function to count inversions in the array
long long merge(vector<long long>& a, int left, int right) {
    if (left + 1 < right) {
        int middle = (left + right) / 2;
        // Recursively count inversions in the left and right halves
        long long x1 = merge(a, left, middle);
        long long x2 = merge(a, middle, right);
        // Merge the two halves and count inversions in the merge step
        long long x3 = sort(a, left, middle, right);
        return x1 + x2 + x3;
    } else {
        return 0;
    }
}

// Main function to read input, count inversions, and print the result
int main() {
    int n;
    cin >> n; // Read the size of the array
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i]; // Read the elements of the array
    cout << merge(a, 0, n) << endl; // Count and print the number of inversions
    return 0;
}

// <END-OF-CODE>
