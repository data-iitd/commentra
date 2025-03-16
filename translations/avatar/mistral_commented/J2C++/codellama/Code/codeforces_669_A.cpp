
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    solve(n);
    return 0;
}

void solve(int n) {
    cout << (n / 3) * 2 + (n % 3 == 0 ? 0 : 1) << endl;
}

