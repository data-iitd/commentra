#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string sa, sb;
    cin >> sa >> sb;

    int a = stoi(sa);
    int b = static_cast<int>(round(stod(sb) * 100));

    cout << (a * b) / 100 << endl;

    return 0;
}

// <END-OF-CODE>
