
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int> &li, int from, int target) {
    int low = from;
    int upp = li.size() - 1;
    int mid = (upp - low + 1) % 2 == 0? (low + upp) / 2 + 1 : (low + upp) / 2;

    if (upp - low < 0) {
        return 0;
    } else if (li[from] >= target) {
        return 0;
    } else if (li[upp] < target) {
        return upp - low + 1;
    }

    while (upp - low > 1) {
        if (li[mid] >= target) {
            upp = mid;
        } else {
            low = mid;
        }
        mid = (upp - low + 1) % 2 == 0? (low + upp) / 2 + 1 : (low + upp) / 2;
    }

    return low - from + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> li;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        li.push_back(x);
    }
    sort(li.begin(), li.end());

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = li[i];
            int b = li[j];
            int res = find(li, j + 1, a + b);
            count += res;
        }
    }
    cout << count << endl;
    return 0;
}

