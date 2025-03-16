#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, levels, level2, level3;
    cin >> n >> levels >> level2;
    level3 = levels + level2;

    vector<int> arr(levels);
    for (int i = 0; i < levels; i++) {
        cin >> arr[i];
    }

    for (int i = levels; i < level3; i++) {
        cin >> arr.push_back();
    }

    vector<int> arr3(n);
    for (int i = 0; i < n; i++) {
        arr3[i] = i + 1;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < arr.size(); x++) {
            if (arr3[i] == arr[x]) {
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
