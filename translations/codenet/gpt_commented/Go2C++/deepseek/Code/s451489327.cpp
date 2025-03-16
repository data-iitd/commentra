#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> as(n + 1);
    std::vector<int> bs(n);

    for (int i = 0; i < n + 1; ++i) {
        std::cin >> as[i];
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> bs[i];
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int a = as[i];
        int b = bs[i];

        if (a <= b) {
            sum += a;
            b -= a;

            if (i + 1 < n) {
                int an = as[i + 1];
                if (an <= b) {
                    sum += an;
                    as[i + 1] = 0;
                } else {
                    sum += b;
                    as[i + 1] -= b;
                }
            }
        } else {
            sum += b;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

