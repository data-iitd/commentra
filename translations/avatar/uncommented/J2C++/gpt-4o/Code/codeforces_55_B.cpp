#include <iostream>
#include <vector>
#include <limits>

using namespace std;

long long minValue;

void util(vector<long long>& arr, string ops[], int idx) {
    if (idx == 3) {
        minValue = min(minValue, arr[0]);
        return;
    }
    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = i + 1; j < arr.size(); j++) {
            vector<long long> a;
            for (size_t k = 0; k < arr.size(); k++) {
                if (k != j && k != i) {
                    a.push_back(arr[k]);
                }
            }
            long long res;
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
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    minValue = numeric_limits<long long>::max();
    vector<long long> arr(4);
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }
    string ops[3];
    for (int i = 0; i < 3; i++) {
        cin >> ops[i];
    }
    util(arr, ops, 0);
    cout << minValue << endl;

    return 0;
}

// <END-OF-CODE>
