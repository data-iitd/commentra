#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt4 = 0, cnt2 = 0;
    // Count multiples of 4 and multiples of 2 (not multiples of 4)
    for (int i = 0; i < n; i++) {
        int wk;
        cin >> wk;
        if (wk % 4 == 0)
            cnt4++;
        else if (wk % 2 == 0)
            cnt2++;
    }

    if (cnt4 + cnt2 / 2 >= n / 2)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

    return 0;
}

// <END-OF-CODE>
