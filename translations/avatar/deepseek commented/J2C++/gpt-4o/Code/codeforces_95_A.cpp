#include <iostream>
#include <vector>
#include <string>
#include <cctype>

class Main {
public:
    // Main logic of the program
    void main() {
        // Reading the number of strings
        int n;
        std::cin >> n;
        std::vector<std::string> ss(n);
        
        // Reading the array of strings
        for (int i = 0; i < n; i++) {
            std::cin >> ss[i];
        }

        // Reading the pattern string and the target character
        std::string cc;
        std::cin >> cc;
        int m = cc.length();
        char c;
        std::cin >> c;
        char c_ = std::toupper(c);
        char a = (c == 'a') ? 'b' : 'a';
        char a_ = std::toupper(a);

        // Array to mark positions in cc that match any string in ss
        std::vector<bool> lucky(m, false);

        // Finding lucky positions and updating characters based on the target character c
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int l = ss[i].length();
                if (m - j >= l && compare(cc, j, ss[i], 0, l) == 0) {
                    for (int h = 0; h < l; h++) {
                        lucky[j + h] = true;
                    }
                }
            }
        }

        // Updating characters in cc based on the lucky positions and target character c
        for (int j = 0; j < m; j++) {
            if (lucky[j]) {
                if (std::tolower(cc[j]) == c) {
                    cc[j] = std::isupper(cc[j]) ? a_ : a;
                } else {
                    cc[j] = std::isupper(cc[j]) ? c_ : c;
                }
            }
        }

        // Printing the modified cc string
        std::cout << cc << std::endl;
    }

private:
    // Compares two character arrays up to a specified length, ignoring case
    int compare(const std::string& aa, int i, const std::string& bb, int j, int m) {
        while (m-- > 0) {
            char a = std::toupper(aa[i]);
            char b = std::toupper(bb[j]);
            if (a != b) return a - b;
            i++;
            j++;
        }
        return 0;
    }
};

int main() {
    Main o;
    o.main();
    return 0;
}

// <END-OF-CODE>
