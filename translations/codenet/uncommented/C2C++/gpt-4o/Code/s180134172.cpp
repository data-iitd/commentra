#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, o = 0;
    cin >> n >> k;
    vector<int> p(n);
    
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    for (int i = 0; i < n; i++) {
        int l = i;
        for (int j = i + 1; j < n; j++) {
            if (p[j] < p[l]) {
                l = j;
            }
        }
        if (l != i) {
            swap(p[i], p[l]);
        }
    }
    
    for (int i = 0; i < k; i++) {
        o += p[i];
    }
    
    cout << o << endl;
    return 0;
}

// <END-OF-CODE>
