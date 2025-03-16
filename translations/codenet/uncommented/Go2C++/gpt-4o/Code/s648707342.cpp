#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Arm {
    int l, r;
};

int main() {
    int n;
    cin >> n;
    vector<Arm> arms(n);
    
    for (int i = 0; i < n; i++) {
        int x, l;
        cin >> x >> l;
        arms[i].l = x - l;
        arms[i].r = x + l;
    }
    
    sort(arms.begin(), arms.end(), [](const Arm &a, const Arm &b) {
        return a.r < b.r;
    });

    int ans = 1;
    int r = arms[0].r;
    for (int i = 1; i < n; i++) {
        if (arms[i].l >= r) {
            ans++;
            r = arms[i].r;
        }
    }
    
    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
