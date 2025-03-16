#include <iostream>
#include <cmath>

int main() {
    long long n;
    std::cin >> n;
    int sqrt_n = static_cast<int>(std::sqrt(n));
    int answer = 0;

    for (int i = 2; i <= sqrt_n; i++) {
        int count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        for (int j = 1; count - j >= 0; j++) {
            count -= j;
            answer++;
        }
    }
    
    if (n > 1) {
        answer++;
    }
    
    std::cout << answer << std::endl;
    return 0;
}

// <END-OF-CODE>
