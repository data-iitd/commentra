
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    solve(n);
    return 0;
}

void solve(int n)
{
    // Calculating the result based on the given logic
    cout << (n / 3) * 2 + (n % 3 == 0? 0 : 1) << endl;
}

