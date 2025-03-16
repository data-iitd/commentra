#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    const int mod = 1000000007;
    int n;
    cin >> n;
    vector<int> as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }
    
    vector<int> xs;
    xs.push_back(as[0]);
    for (int j = 1; j < n; j++) {
        auto idx = lower_bound(xs.begin(), xs.end(), as[j]);
        if (idx == xs.end()) {
            xs.push_back(as[j]);
        } else {
            *idx = as[j];
        }
    }
    
    cout << xs.size() << endl;
    return 0;
}

// <END-OF-CODE>
