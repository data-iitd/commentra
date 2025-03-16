#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int menu[5][2];
    for (int i = 0; i < 5; i++) {
        cin >> menu[i][0];
        menu[i][1] = menu[i][0] % 10;
        if (menu[i][1] == 0) menu[i][1] = 10;
    }
    sort(menu, menu + 5, [](int a, int b) { return a[1] < b[1]; });
    int ans = 0;
    for (int i = 1; i < 5; i++) {
        int num_full_10s = ceil(menu[i][0] / 10.0);
        ans += num_full_10s * 10;
    }
    cout << menu[0][0] + ans << endl;
    return 0;
}
