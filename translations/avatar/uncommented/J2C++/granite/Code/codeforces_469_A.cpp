
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, levels;
    cin >> n >> levels;
    vector<int> arr(levels);
    for (int i = 0; i < levels; i++) {
        cin >> arr[i];
    }
    int level2, level3;
    cin >> level2 >> level3;
    vector<int> arr2(level3);
    for (int i = 0; i < arr.size(); i++) {
        arr2[i] = arr[i];
    }
    for (int i = arr.size(); i < level3; i++) {
        cin >> arr2[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (find(arr2.begin(), arr2.end(), i + 1)!= arr2.end()) {
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
//END-OF-CODE