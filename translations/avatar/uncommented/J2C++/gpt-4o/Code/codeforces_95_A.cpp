#include <iostream>
#include <vector>
#include <string>
#include <cctype>

class Main {
public:
    void run() {
        int n;
        std::cin >> n;
        std::vector<std::string> ss(n);
        for (int i = 0; i < n; i++) {
            std::cin >> ss[i];
        }
        std::string cc;
        std::cin >> cc;
        int m = cc.length();
        char c;
        std::cin >> c;
        char c_ = toupper(c);
        char a = (c == 'a') ? 'b' : 'a';
        char a_ = toupper(a);
        std::vector<bool> lucky(m, false);

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

        for (int j = 0; j < m; j++) {
            if (lucky[j]) {
                if (tolower(cc[j]) == c) {
                    cc[j] = isupper(cc[j]) ? a_ : a;
                } else {
                    cc[j] = isupper(cc[j]) ? c_ : c;
                }
            }
        }
        std::cout << cc << std::endl;
    }

private:
    int compare(const std::string& aa, int i, const std::string& bb, int j, int m) {
        while (m-- > 0) {
            char a = toupper(aa[i]);
            char b = toupper(bb[j]);
            if (a != b) return a - b;
            i++;
            j++;
        }
        return 0;
    }
};

int main() {
    Main o;
    o.run();
    return 0;
}

// <END-OF-CODE>
