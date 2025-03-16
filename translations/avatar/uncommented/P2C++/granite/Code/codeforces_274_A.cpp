
#include <bits/stdc++.h>
using namespace std;

int main() {
    int num, k;
    cin >> num >> k;
    vector<int> arr(num);
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    set<int> different;
    int temp = 0;
    for (int i = 0; i < num; i++) {
        if (arr[i] % k!= 0 || different.find(arr[i] / k) == different.end()) {
            different.insert(arr[i]);
        }
        temp = max(temp, (int)different.size());
    }
    cout << temp << endl;
    return 0;
}

