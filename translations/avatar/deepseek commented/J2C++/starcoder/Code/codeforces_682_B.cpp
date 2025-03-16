#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> list;
    
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
    
    sort(list.begin(), list.end());
    
    int c = 1;
    
    for (int i = 0; i < n; i++) {
        if (list[i] >= c) {
            c++;
        }
    }
    
    cout << c << "\n";
}

