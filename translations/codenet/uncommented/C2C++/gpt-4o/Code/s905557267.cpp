#include <iostream>
#include <vector>

int min(int a, int b) {
    return (a <= b) ? a : b;
}

int Chain(std::vector<int>& b, int n) {
    int count;
    int color;
    std::vector<int> a = b; // Copy the input array

    for (int i = 0; i < n - 4; i++) {
        if (a[i] != 0 && a[i] == a[i + 1] && a[i] == a[i + 2] && a[i] == a[i + 3]) {
            count = 0;
            color = a[i];

            for (int j = i; a[j] == color; j++) {
                a[j] = 0;
                count++;
            }

            for (int j = 0; i + j + count < 10000; j++) {
                a[i + j] = a[i + j + count];
                a[i + j + count] = 0;
            }

            i = -1; // Reset i to start from the beginning
        }
    }

    count = 0;
    while (count < n && a[count] != 0) {
        count++;
    }

    if (count == 4 && a[0] == a[1] && a[0] == a[2] && a[0] == a[3]) {
        return 0;
    }

    return count;
}

int main() {
    int n;
    while (true) {
        std::vector<int> a(10000, 0); // Initialize vector with zeros

        std::cin >> n;
        if (n == 0) {
            break;
        }
        int ans = n;

        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        for (int i = 0; i < n - 4; i++) {
            int count[3] = {0, 0, 0};
            for (int j = i; j < i + 4; j++) {
                if (a[j] - 1 >= 0) {
                    count[a[j] - 1]++;
                }
            }

            int color = 0;
            for (int j = 0; j < 3; j++) {
                if (count[j] >= 3) {
                    color = j + 1;
                    break;
                }
            }

            if (color != 0) {
                for (int j = i; j < i + 4; j++) {
                    int buf = a[j];
                    a[j] = color;
                    ans = min(ans, Chain(a, n));
                    a[j] = buf;
                }
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
