#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Step 1: Take an integer input `n` which represents the number of elements in the list `l1`.
    int n;
    std::cin >> n;

    // Step 2: Take a space-separated string of integers, convert them into a list of integers, and store it in `l1`.
    std::vector<int> l1(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> l1[i];
    }

    // Step 3: Sort the list `l1` in ascending order.
    std::sort(l1.begin(), l1.end());

    // Step 4: Assign the last element of the sorted list `l1` to `a`, which is the maximum value in the list.
    int a = l1[n - 1];

    // Step 5: Assign the first element of the sorted list `l1` to `b`, which is the minimum value in the list.
    int b = l1[0];

    // Step 6: Check if `a` is equal to `b`.
    if (a == b) {
        // Step 7: If `a` is equal to `b`, print the difference `a - b` and the number of ways to choose 2 elements from `n` elements.
        std::cout << a - b << " " << n * (n - 1) / 2 << std::endl;
    } else {
        // Step 8: If `a` is not equal to `b`, calculate the count of occurrences of `a` and `b` in the list `l1`.
        int ac = std::count(l1.begin(), l1.end(), a);
        int bc = std::count(l1.begin(), l1.end(), b);
        // Step 9: Print the difference `a - b` and the product of the counts of `a` and `b`.
        std::cout << a - b << " " << ac * bc << std::endl;
    }

    return 0;
}
// <END-OF-CODE>
