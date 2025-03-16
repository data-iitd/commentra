#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    // Step 2: Create a vector 'a' of size n and read n elements from the input.
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Step 3: Sort the vector 'a'.
    std::sort(a.begin(), a.end());

    // Step 4: Find the minimum element in the sorted vector 'a'.
    int min = a[0];

    // Step 5: Check if all elements in the vector are divisible by the minimum element. If not, print -1 and exit.
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
