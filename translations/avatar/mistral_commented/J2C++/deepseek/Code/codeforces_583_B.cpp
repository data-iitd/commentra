#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> a(n);
        vector<int> b(n, 0);
        int s = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int tem = 1;
        int q = 0;
        while (q != n) {
            s++;
            if (tem == 1) {
                for (int i = 0; i < n; i++) {
                    if (a[i] <= q && b[i] == 0) {
                        b[i] = 1;
                    }
                }
                tem = 0;
            } else {
                for (int i = n - 1; i >= 0; i--) {
                    if (a[i] <= q && b[i] == 0) {
                        b[i] = 1;
                    }
                }
                tem = 1;
            }
            q++;
        }
        cout << s << endl;
    }
    return 0;
}
