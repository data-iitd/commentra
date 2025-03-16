

#include <bits/stdc++.h>
using namespace std;

int main() {
    int num, k;
    cin >> num >> k;  // Read the number of elements and the divisor
    vector<int> arr(num);  // Initialize a vector to store the array of integers
    set<int> different;  // Initialize a set to keep track of unique elements not divisible by k
    int temp = 0;  // Initialize a variable to store the maximum length of the set

    // Read the array of integers and sort it
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    // Iterate through each element in the sorted array
    for (int x : arr) {
        if (x % k!= 0 || different.find(x / k) == different.end()) {  // Check if x is not divisible by k or x/k is not in the set
            different.insert(x);  // Add x to the set if the condition is true
        }
        temp = max(different.size(), temp);  // Update temp with the maximum length of the set
    }

    cout << temp << endl;  // Print the maximum number of unique elements not divisible by k

    return 0;
}
