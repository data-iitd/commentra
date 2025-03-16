#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> na() {
    vector<int> result;
    int num;
    while (cin >> num) {
        result.push_back(num);
        if (cin.peek() == '\n') break; // Stop reading on newline
    }
    return result;
}

int main() {
    vector<int> firstInput = na();
    int n = firstInput[0];
    int x = firstInput[1];
    
    vector<int> a = na();
    sort(a.begin(), a.end());
    
    int ans = 0;
    if (a[0] > x) {
        cout << 0 << endl;
        return 0;
    }
    
    for (int i : a) {
        if (i > x) {
            x = 0;
            break;
        }
        x -= i;
        ans++;
    }
    
    if (x != 0) {
        ans--;
    }
    
    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
