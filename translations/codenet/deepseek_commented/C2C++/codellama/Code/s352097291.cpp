#include <iostream>
#include <string>

using namespace std;

int main() {
    string c, ans = "";
    cin >> c;

    for (int i = 0; i < c.length(); i++) {
        if (c[i] != 'B')
            ans += c[i];
        else
            ans.erase(ans.length() - 1);
    }

    cout << ans << endl;
}

