#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

int main() {
    int n;
    scanf("%d", &n);

    if (n == 1) {
        int x;
        scanf("%d", &x);
        printf("%d\n", x);
        return 0;
    }

    std::vector<int> a;

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        a.push_back(num);
    }

    std::sort(a.begin(), a.end());

    if (a.back() == 0) {
        printf("0\n");
        return 0;
    }

    int ans = 0;

    while (true) {
        if (a.size() == 1) {
            ans = a[0];
            break;
        }
        a = func(a);
    }

    printf("%d\n", ans);
    return 0;
}

std::vector<int> func(std::vector<int> A) {
    std::vector<int> a = A;
    int min = 0;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 0) {
            a.erase(a.begin() + i);
            i--;
        } else {
            if (min != 0) {
                a[i] = a[i] % min;
                if (a[i] == 1) {
                    printf("1\n");
                    exit(0);
                }
            } else {
                min = a[i];
            }
        }
    }

    std::sort(a.begin(), a.end());
    return a;
}
