#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Step 1: Read the input value n, which represents the number of elements in the array.
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    
    // Step 2: Create an array 'a' of size n and read n elements from the input.
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    // Step 3: Sort the array 'a'.
    std::sort(a.begin(), a.end());
    
    // Step 4: Find the minimum element in the sorted array 'a'.
    int min = a[0];
    
    // Step 5: Check if all elements in the array are divisible by the minimum element. If not, print -1 and exit.
    for (int value : a) {
        if (value % min != 0) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }
    
    // Step 6: If all elements are divisible, print the minimum element.
    std::cout << min << std::endl;
    
    return 0;
}

// <END-OF-CODE>
