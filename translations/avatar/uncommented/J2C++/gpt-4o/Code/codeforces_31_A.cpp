#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int f = 0;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int k, j, i;
    for (k = 0; k < n; k++) {
        int t = a[k];
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - 1; j++) {
                if (i != j && t == (a[i] + a[j])) {
                    f = 1;
                    break;
                }
            }
            if (f == 1) break;
        }
        if (f == 1) break;
    }
    
    if (f == 1) {
        cout << k + 1 << " " << j + 1 << " " << i + 1 << endl;
    } else {
        cout << "-1" << endl;
    }
    
    return 0;
}

// <END-OF-CODE>
