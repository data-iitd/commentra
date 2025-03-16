
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> s(n);
    for (int i = 0; i < n; i++) {
        char c;
        std::cin >> c;
        switch (c) {
            case 'R':
                s[i] = 0;
                break;
            case 'G':
                s[i] = 1;
                break;
            case 'B':
                s[i] = 2;
                break;
        }
    }

    std::vector<std::vector<int>> rgb(n + 1, std::vector<int>(3));
    rgb[0][0] = 0;
    rgb[0][1] = 0;
    rgb[0][2] = 0;
    for (int i = 1; i <= n; i++) {
        rgb[i][0] = rgb[i - 1][0];
        rgb[i][1] = rgb[i - 1][1];
        rgb[i][2] = rgb[i - 1][2];
        rgb[i][s[i - 1]]++;
    }
    int sum = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (s[i]!= s[j]) {
                int tn = 3 - s[i] - s[j];
                sum += rgb[n][tn] - rgb[j + 1][tn];
                int k = 2 * j - i;
                if (k < n && s[k] == tn) {
                    sum--;
                }
            }
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
