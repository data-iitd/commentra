#include <iostream>
#include <vector>

int main() {
    long int n;

    std::cin >> n;
    std::vector<long int> a(n);
    std::vector<long int> count(n, 0);

    for (long int i = 1; i < n; i++)
        std::cin >> a[i];

    for (long int i = 1; i < n; i++)
        count[a[i] - 1]++;

    for (long int i = 0; i < n; i++)
        std::cout << count[i] << std::endl;

    return 0;
}

// <END-OF-CODE>
