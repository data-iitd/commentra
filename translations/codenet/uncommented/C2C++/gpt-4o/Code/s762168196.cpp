#include <iostream>
#include <vector>

int main() {
    std::vector<int> a(10000);
    int min, max, n;
    long long sum = 0;

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum += a[i];
    }

    max = min = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] > max) max = a[i];
        if(a[i] < min) min = a[i];
    }

    std::cout << min << " " << max << " " << sum << std::endl;

    return 0;
}

// <END-OF-CODE>
