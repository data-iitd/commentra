
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(33, 0);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        int k = 0;
        while (x > 0) {
            if (x % 2 == 1) {
                k++;
            }
            x /= 2;
        }
        a[k]++;
    }
    double answer = 0;
    for (int i = 0; i < a.size(); i++) {
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1);
        answer += summ;
    }
    cout << (ll)answer << endl;
    return 0;
}
//END-OF-CODE