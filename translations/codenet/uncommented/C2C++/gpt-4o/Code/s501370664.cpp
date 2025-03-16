#include <iostream>
#include <vector>

std::vector<int> flag;

void prime(int num) {
    flag.resize(num + 1, 0);

    for (int i = 2; i * i <= num; i++) {
        if (flag[i] == 0) {
            for (int j = 2; i * j <= num; j++) {
                flag[i * j] = 1;
            }
        }
    }
}

int main() {
    int n, cnt;

    prime(50000);

    while (true) {
        std::cin >> n;
        if (n == 0) {
            break;
        }
        int i = 2;
        cnt = 0;
        while (i * 2 <= n) {
            if (!flag[i] && !flag[n - i]) {
                cnt++;
            }
            i++;
        }
        std::cout << cnt << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
