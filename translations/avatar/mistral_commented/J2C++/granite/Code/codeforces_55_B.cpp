

#include <bits/stdc++.h>
using namespace std;

long long min = LLONG_MAX;

void util(vector<long long> &arr, vector<string> &ops, int idx) {
    if (idx == 3) {
        min = min(min, arr[0]);
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            vector<long long> a;
            for (int k = 0; k < arr.size(); k++) {
                if (k!= j && k!= i) {
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
    vector<long long> arr;
    vector<string> ops;

    for (int i = 0; i < 4; i++) {
        long long num;
        cin >> num;
        arr.push_back(num);
    }

    for (int i = 0; i < 3; i++) {
        string op;
        cin >> op;
        ops.push_back(op);
    }

    util(arr, ops, 0);

    cout << min << endl;

    return 0;
}

This code is almost identical to the Java code, with minor syntax differences. The main difference is that C++ does not have a built-in Long type, so we use long long instead. The rest of the code is the same, with the util method recursively calling itself to perform the operations.

Please note that the code assumes that the input numbers and operators are valid. You may need to add additional error handling code if necessary.

Let me know if you have any further questions or need assistance with anything else.