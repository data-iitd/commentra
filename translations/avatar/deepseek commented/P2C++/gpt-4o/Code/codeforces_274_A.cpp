#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int num, k;
    std::cin >> num >> k;  // Read the number of elements and the divisor
    std::vector<int> arr(num);  // Initialize a vector to store the array of integers

    for (int i = 0; i < num; ++i) {
        std::cin >> arr[i];  // Read the array of integers
    }

    std::set<int> different;  // Initialize a set to keep track of unique elements not divisible by k
    int temp = 0;  // Initialize a variable to store the maximum length of the set
    std::sort(arr.begin(), arr.end());  // Sort the array

    // Iterate through each element in the sorted array
    for (int x : arr) {
        if (x % k != 0 || different.find(x / k) == different.end()) {  // Check if x is not divisible by k or x/k is not in the set
            different.insert(x);  // Add x to the set if the condition is true
        }
        temp = std::max(static_cast<int>(different.size()), temp);  // Update temp with the maximum length of the set
    }

    std::cout << temp << std::endl;  // Print the maximum number of unique elements not divisible by k
    return 0;
}  // <END-OF-CODE>
