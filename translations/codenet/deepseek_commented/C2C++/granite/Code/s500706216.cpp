
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> light(n + 10, 0);
    for (int i = 0; i < n; i++) {
        int r = i - a[i];
        int l = i + a[i];
        light[(r < 0? 0 : r)]++;
        light[(l + 1 > n? n + 1 : l + 1)]--;
    }
    for (int i = 0; i < k; i++) {
        vector<int> tmpa = a;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += light[j];
            a[j] = sum;
        }
        for (int j = 0; j < n; j++) {
            int r = j - tmpa[j];
            int l = j + tmpa[j];
            light[(r < 0? 0 : r)]--;
            light[(l + 1 > n? n + 1 : l + 1)]++;
            r = j - a[j];
            l = j + a[j];
            light[(r < 0? 0 : r)]++;
            light[(l + 1 > n? n + 1 : l + 1)]--;
        }
        bool isSame = true;
        for (int j = 0; j < n - 1; j++) {
            if (a[j]!= a[j + 1]) {
                isSame = false;
                break;
            }
        }
        if (isSame && a[0] == n) {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1? "\n" : " ");
    }
    return 0;
}

