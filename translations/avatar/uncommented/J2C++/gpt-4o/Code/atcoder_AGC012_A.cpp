#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> array(3 * n);
    
    for (int i = 0; i < array.size(); i++) {
        cin >> array[i];
    }
    
    sort(array.begin(), array.end());
    int head = array.size() - 2;
    long long res = 0;
    
    for (int i = 0; i < n; i++) {
        res += array[head];
        head -= 2;
    }
    
    cout << res << endl;
    return 0;
}

// <END-OF-CODE>
