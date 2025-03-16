#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> map;
    
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        map[val]++;
    }
    
    int max_count = INT_MIN;
    for (const auto& entry : map) {
        max_count = max(max_count, entry.second);
    }
    
    cout << max_count << map.size() << endl;
    
    return 0;
}

// <END-OF-CODE>
