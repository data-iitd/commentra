#include <bits/stdc++.h>
using namespace std;

int main() {
    // Creating a Scanner object to read input from the user
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    int array[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> array[i];
    }
    int odd = 0, even = 0, odd_ind = 0, even_ind = 0;
    for (int i = 1; i <= n; i++) {
        if (array[i] % 2 == 0) {
            even++;
            even_ind = i;
        } else {
            odd++;
            odd_ind = i;
        }
    }
    if (odd > even) {
        cout << even_ind;
    } else {
        cout << odd_ind;
    }
    return 0;
}

