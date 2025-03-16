
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "";
    for (int i = 0; i < n; i++) {
        s += "abcd"[i % 4];
    }
    cout << s << endl;
    return 0;
}
