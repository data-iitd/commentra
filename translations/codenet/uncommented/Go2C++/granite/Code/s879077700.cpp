
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    cin >> a;
    string ans = "Good";
    for (int i = 0; i < 3; i++) {
        if (a[i] == a[i+1]) {
            ans = "Bad";
        }
    }
    cout << ans << endl;
    return 0;
}
// END-OF-CODE