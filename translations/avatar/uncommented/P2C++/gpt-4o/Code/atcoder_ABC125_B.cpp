#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    
    vector<int> list = {0};
    int ans = 0;
    int X = 0, Y = 0;
    
    for (int i = 0; i < N; i++) {
        if (V[i] - C[i] > 0) {
            X = V[i];
            Y = C[i];
            list.push_back(X - Y);
        }
    }
    
    for (int i = 0; i < list.size(); i++) {
        ans += list[i];
    }
    
    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
