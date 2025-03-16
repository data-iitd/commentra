#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>

class Main {
private:
    int n;
    std::vector<int> a;
    std::map<int, int> s;

public:
    void solve() {
        set();
        int ng = 0;
        int ok = n;
        while (ok - ng > 1) {
            int k = (ng + ok) / 2;
            if (isPossible(k)) {
                ok = k;
            } else {
                ng = k;
            }
        }
        std::cout << ok << std::endl;
    }

private:
    void set() {
        std::cin >> n;
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
    }

    bool isPossible(int k) {
        s.clear();
        int current = 0;
        for (int ai : a) {
            if (ai <= current) {
                if (k == 1) return false;
                while (!s.empty() && s.rbegin()->first >= ai) {
                    s.erase(--s.end());
                }
                int p = ai - 1;
                while (true) {
                    if (p < 0) return false;
                    int sp = s[p] + 1;
                    s[p] = sp;
                    if (sp == k) {
                        s.erase(p);
                        p--;
                    } else {
                        break;
                    }
                }
            }
            current = ai;
        }
        return true;
    }
};

int main() {
    Main m;
    m.solve();
    return 0;
}

// <END-OF-CODE>
