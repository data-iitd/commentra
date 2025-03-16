#include <iostream>
#include <vector>

int main() {
    // Read the integer n and the string s from the standard input
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    // Convert the characters in s to their corresponding integer values
    // 'R' -> 0, 'G' -> 1, 'B' -> 2
    std::vector<int> ns(n);
    for (int i = 0; i < n; i++) {
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

    // Construct a cumulative count array rgb to keep track of the counts of each color up to each position
    std::vector<std::vector<int>> rgb(n + 1, std::vector<int>(3, 0));
    for (int i = 1; i <= n; i++) {
        rgb[i] = rgb[i - 1];
        rgb[i][ns[i - 1]]++;
    }

    // Calculate the number of valid triplets (i, j, k) where ns[i] != ns[j] != ns[k] and ns[k] == tn
    // where tn is the third color different from ns[i] and ns[j]
    int sum = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (ns[i] != ns[j]) {
                int tn = 3 - ns[i] - ns[j];
                sum += rgb[n][tn] - rgb[j + 1][tn];
                int k = 2 * j - i;
                if (k < n && ns[k] == tn) {
                    sum--;
                }
            }
        }
    }

    // Print the result
    std::cout << sum << std::endl;

    return 0;
}

// <END-OF-CODE>
