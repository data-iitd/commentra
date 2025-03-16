#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    unordered_set<int> set1, set2;

    for (int i = 0; i < a; i++) {
        int temp;
        cin >> temp;
        set1.insert(temp);
    }

    for (int i = 0; i < b; i++) {
        int temp;
        cin >> temp;
        set2.insert(temp);
    }

    for (int i = 0; i < n; i++) {
        if (set1.find(i + 1) != set1.end()) {
            cout << 1 << " ";
        } else {
            cout << 2 << " ";
        }
    }

    return 0;
}

// <END-OF-CODE>
