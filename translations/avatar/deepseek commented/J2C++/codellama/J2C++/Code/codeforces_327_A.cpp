#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int x = 0;
            int brr[n];
            for (int k = 0; k < n; k++) {
                brr[k] = arr[k];
            }
            for (int k = i; k <= j; k++) {
                if (brr[k] == 0) {
                    brr[k] = 1;
                } else {
                    brr[k] = 0;
                }
            }
            int count = 0;
            for (int k = 0; k < n; k++) {
                if (brr[k] == 1) {
                    count++;
                }
            }
            if (count > max) {
                max = count;
            }
        }
    }
    if (n == 1) {
        if (arr[0] == 1) {
            cout << 0;
        } else {
            cout << 1;
        }
    } else {
        cout << max;
    }
    return 0;
}

