#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n; // 1. Reading the input size `n`

    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i]; // 2. Reading the array elements
    }

    std::vector<long long> abs_a = a; // 3. Creating a copy of the array with absolute values

    for (int i = 0; i < n; i++) {
        if (abs_a[i] < 0) {
            abs_a[i] = -abs_a[i];
        }
    }

    long long ans = 0; // 4. Calculating the sum of absolute values
    long long min = abs_a[0];
    for (auto e : abs_a) {
        ans += e;
        if (min > e) {
            min = e;
        }
    }

    int num_negative = 0; // 5. Counting the number of negative elements
    for (auto e : a) {
        if (e < 0) {
            num_negative++;
        }
    }

    if (num_negative % 2) { // 6. Adjusting the sum based on the number of negative elements
        ans -= min * 2;
    }

    std::cout << ans << std::endl; // 7. Outputting the result
}
