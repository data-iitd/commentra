#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), tmpa(n);
    vector<int> light(n + 10, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        int r = i - a[i];
        int l = i + a[i];
        light[max(0, r)]++;
        light[min(n + 1, l + 1)]--;
    }

    for (int i = 0; i < k; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            tmpa[j] = a[j];
            sum += light[j];
            a[j] = sum;
        }
        for (int j = 0; j < n; j++) {
            int r = j - tmpa[j];
            int l = j + tmpa[j];
            light[max(0, r)]--;
            light[min(n + 1, l + 1)]++;
            r = j - a[j];
            l = j + a[j];
            light[max(0, r)]++;
            light[min(n + 1, l + 1)]--;
        }
        bool isSame = true;
        for (int j = 0; j < n - 1; j++) {
            if (a[j] != a[j + 1]) {
                isSame = false;
                break;
            }
        }
        if (isSame && a[0] == n) {
            break;
        }
    }

    for (int j = 0; j < n; j++) {
        cout << a[j] << (j == n - 1 ? "\n" : " ");
    }
    return 0;
}

// <END-OF-CODE>
