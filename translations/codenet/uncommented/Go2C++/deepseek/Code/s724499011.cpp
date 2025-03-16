#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> ns(n);
    for (int i = 0; i < n; ++i) {
        switch (s[i]) {
            case 'R':
                ns[i] = 0;
                break;
            case 'G':
                ns[i] = 1;
                break;
            case 'B':
                ns[i] = 2;
                break;
        }
    }

    std::vector<std::vector<int>> rgb(n + 1, std::vector<int>(3));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            rgb[i][j] = rgb[i - 1][j];
        }
        ++rgb[i][ns[i - 1]];
    }

    int sum = 0;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            if (ns[i] != ns[j]) {
                int tn = 3 - ns[i] - ns[j];
                sum += rgb[n][tn] - rgb[j + 1][tn];
                int k = 2 * j - i;
                if (k < n && ns[k] == tn) {
                    --sum;
                }
            }
        }
    }

    std::cout << sum << std::endl;
    return 0;
}

