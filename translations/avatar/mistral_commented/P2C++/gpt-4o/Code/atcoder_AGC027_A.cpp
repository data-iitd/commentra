#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> na() {
    vector<int> result;
    int num;
    while (cin >> num) {
        result.push_back(num);
        if (cin.peek() == '\n') break; // Break on newline
    }
    return result;
}

int main() {
    vector<int> input = na();
    int n = input[0];
    int x = input[1];

    vector<int> a;
    for (int i = 2; i < input.size(); i++) {
        a.push_back(input[i]);
    }
    sort(a.begin(), a.end());

    int ans = 0;

    if (a[0] > x) {
        cout << 0 << endl;
        return 0;
    }

    for (int i : a) {
        if (i > x) {
            x = 0;
            break;
        }
        x -= i;
        ans++;
    }

    if (x != 0) {
        ans--;
    }

    cout << ans << endl;

    return 0;
}
// <END-OF-CODE>
