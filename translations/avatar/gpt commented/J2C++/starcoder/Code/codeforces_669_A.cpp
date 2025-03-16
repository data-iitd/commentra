#include <bits/stdc++.h>
using namespace std;

int main() {
    // Reading an integer input from the user
    int n;
    cin >> n;
    
    // Calling the solve method with the input integer
    solve(n);
}

void solve(int n) {
    // Calculating and printing the result based on the input integer n
    // The formula calculates (n / 3) * 2 and adds 1 if n is not divisible by 3
    cout << ((n / 3) * 2 + (n % 3 == 0? 0 : 1)) << endl;
}

