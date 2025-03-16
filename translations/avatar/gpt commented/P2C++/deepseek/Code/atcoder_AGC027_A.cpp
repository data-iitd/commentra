#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Define a lambda function to read a list of integers from input
    auto read_ints = []() {
        std::vector<int> numbers;
        int num;
        while (std::cin >> num) {
            numbers.push_back(num);
        }
        return numbers;
    };

    // Read the number of elements (n) and the initial value (x) from input
    int n, x;
    std::cin >> n >> x;

    // Read and sort the list of integers
    std::vector<int> a = read_ints();
    std::sort(a.begin(), a.end());

    // Initialize the answer counter
    int ans = 0;

    // Check if the smallest element in the sorted list is greater than x
    if (a[0] > x) {
        // If true, print 0 and exit since no elements can be subtracted from x
        std::cout << 0 << std::endl;
        return 0;
    }

    // Iterate through the sorted list of integers
    for (int i : a) {
        // If the current element is greater than x, set x to 0 and break the loop
        if (i > x) {
            x = 0;
            break;
        }
        // Subtract the current element from x
        x -= i;
        // Increment the answer counter
        ans += 1;
    }

    // If there is any remaining value in x, decrement the answer counter
    if (x != 0) {
        ans -= 1;
    }

    // Print the final answer
    std::cout << ans << std::endl;

    return 0;
}
