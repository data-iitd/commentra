#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    cout << max(x + y - 3 + ((y - x) % 3 > 0), 0) << endl;

    // The following functions are equivalent to the Python lambdas
    auto num_inp = []() {
        int n;
        cin >> n;
        return n;
    };

    auto arr_inp = []() {
        int n;
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        return arr; // Note: Remember to delete the array after use
    };

    auto sp_inp = []() {
        int x, y;
        cin >> x >> y;
        return make_pair(x, y);
    };

    auto str_inp = []() {
        string s;
        cin >> s;
        return s;
    };

    return 0;
}

// <END-OF-CODE>
