
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long min;

void util(vector<long> arr, string ops[], int idx) {
    if (idx == 3) {
        min = min < arr[0] ? min : arr[0];
        return;
    }
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            vector<long> a;
            for (int k = 0; k < arr.size(); k++) {
                if (k != j && k != i) {
                    a.push_back(arr[k]);
                }
            }
            long res;
            if (idx < 3 && ops[idx] == "+") {
                res = arr[i] + arr[j];
            } else {
                res = arr[i] * arr[j];
            }
            a.push_back(res);
            util(a, ops, idx + 1);
        }
    }
}

int main() {
    long n;
    cin >> n;
    vector<long> arr;
    for (int i = 0; i < 4; i++) {
        long x;
        cin >> x;
        arr.push_back(x);
    }
    string ops[3];
    for (int i = 0; i < 3; i++) {
        cin >> ops[i];
    }
    min = LONG_MAX;
    util(arr, ops, 0);
    cout << min << endl;
    return 0;
}

