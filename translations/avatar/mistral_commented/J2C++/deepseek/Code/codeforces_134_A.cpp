#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        sum += arr[i];
    }

    int c = 0;
    std::string indices;

    for (int i = 0; i < n; i++) {
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
            c++;
            indices += std::to_string(i + 1) + " ";
        }
    }

    std::cout << c << std::endl;
    std::cout << indices << std::endl;

    return 0;
}
