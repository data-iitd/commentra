#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cmath>

int main() {
    int x[3];
    int max = 0;

    // Step 1: Read input values for the array x and find the maximum value in x.
    for (int i = 0; i < 3; ++i) {
        std::cin >> x[i];
        max = std::max(max, x[i]);
    }

    int k;
    std::cin >> k;
    std::vector<std::list<long long>> a[3];

    // Step 2: Initialize a list of lists to store the input values for each sub-array.
    for (int i = 0; i < 3; ++i) {
        a[i] = std::list<long long>();
    }

    // Step 3: Read input values for each sub-array, sort them, and store them in the list of lists.
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < x[i]; ++j) {
            long long value;
            std::cin >> value;
            a[i].push_back(value);
        }
        a[i].sort();
    }

    std::vector<long long> ans;

    // Step 5: Initialize an empty list to store the results.
    // Step 6: Use nested loops to iterate through all possible combinations of elements from the three sub-arrays,
    // and add the sum of the selected elements to the result list if the product of their indices is less than or equal to k.
    for (int i = 0; i < x[0]; ++i) {
        for (int j = 0; j < x[1]; ++j) {
            for (int m = 0; m < x[2]; ++m) {
                if ((i + 1) * (j + 1) * (m + 1) <= k) {
                    long long tmp = *(a[0].rbegin() + i) + *(a[1].rbegin() + j) + *(a[2].rbegin() + m);
                    ans.push_back(tmp);
                }
            }
        }
    }

    // Step 7: Sort the result list in ascending order.
    std::sort(ans.begin(), ans.end());

    int n = ans.size();

    // Step 8: Print the top k values from the result list in descending order.
    for (int i = 0; i < k; ++i) {
        std::cout << ans[n - i - 1] << std::endl;
    }

    return 0;
}
