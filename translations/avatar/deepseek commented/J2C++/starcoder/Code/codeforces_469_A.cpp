
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, levels, level2, level3, count = 0;
    cin >> n >> levels;
    int arr[levels];
    for (int i = 0; i < levels; i++) {
        cin >> arr[i];
    }
    cin >> level2;
    level3 = levels + level2;
    int arr2[level3];
    for (int i = 0; i < arr.length; i++) {
        arr2[i] = arr[i];
    }
    for (int i = arr.length; i < level3; i++) {
        cin >> arr2[i];
    }
    int arr3[n];
    for (int i = 0; i < n; i++) {
        arr3[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < arr2.length; x++) {
            if (arr3[i] == arr2[x]) {
                count++;
                break;
            }
        }
    }
    if (count == n) {
        cout << "I become the guy." << endl;
    } else {
        cout << "Oh, my keyboard!" << endl;
    }
    return 0;
}

