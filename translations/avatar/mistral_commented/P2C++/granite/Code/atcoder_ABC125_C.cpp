
#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    // Base case: if b is 0, return a as the GCD
    if (b == 0) {
        return a;
    }
    // Recursive case: find the GCD of b and the remainder of a divided by b
    return gcd(b, a % b);
}

// Function to perform Ruiseki algorithm on a given array
std::vector<int> ruiseki_lr(const std::vector<int>& array) {
    // Define a helper function to find the GCD of two numbers
    auto op = [](int a, int b) { return gcd(a, b); };
    // Initialize empty vector 'left' of size 'n+1'
    int e = 0;
    int n = array.size();
    std::vector<int> left(n + 1, e);
    // Iterate through the array and calculate the left array
    for (int i = 0; i < n; i++) {
        left[i + 1] = op(left[i], array[i]);
    }
    // Return the calculated left array
    return left;
}

int main() {
    // Read input from the user: number of elements in the array and the array itself
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    // Perform Ruiseki algorithm on the given array and get the left array
    auto left = ruiseki_lr(a);
    // Initialize answer variable with 0
    int ans = 0;
    // Iterate through the array and find the maximum GCD between adjacent elements in the left array
    for (int i = 0; i < n; i++) {
        ans = std::max(gcd(left[i], left[i + 1]), ans);
    }
    // Print the final answer
    std::cout << ans << std::endl;
    return 0;
}

