

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, levels, sum = 0, sum2 = 0, sum3 = 0, count = 0;
    cin >> n >> levels;
    vector<int> arr(levels);
    for (int i = 0; i < levels; i++) {
        cin >> arr[i];
    }
    int level2;
    cin >> level2;
    int level3 = levels + level2;
    vector<int> arr2(level3);
    for (int i = 0; i < arr.size(); i++) {
        arr2[i] = arr[i];
    }
    for (int i = arr.size(); i < level3; i++) {
        cin >> arr2[i];
    }
    vector<int> arr3(n);
    for (int i = 0; i < n; i++) {
        arr3[i] = i + 1;
    }
    sort(arr2.begin(), arr2.end());
    for (int i = 0; i < n; i++) {
        if (binary_search(arr2.begin(), arr2.end(), arr3[i])) {
            count++;
        }
    }
    if (count == n) {
        cout << "I become the guy." << endl;
    } else {
        cout << "Oh, my keyboard!" << endl;
    }
    return 0;
}
