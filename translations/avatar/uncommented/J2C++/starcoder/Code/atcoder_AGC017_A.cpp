#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p;
    int k0 = 0, k1 = 0;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 1) k1++;
        else k0++;
    }
    BigInteger ans = new BigInteger("1");
    for (int i = 0; i < k0; i++) ans = ans.multiply(BigInteger.valueOf(2));
    if (p == 0) {
        BigInteger add = new BigInteger("0");
        for (int i = 0; i <= k1; i += 2) add = add.add(C(i, k1));
        ans = ans.multiply(add);
        cout << ans << endl;
    } else {
        BigInteger add = new BigInteger("0");
        for (int i = 1; i <= k1; i += 2) add = add.add(C(i, k1));
        ans = ans.multiply(add);
        cout << ans << endl;
    }
    return 0;
}

