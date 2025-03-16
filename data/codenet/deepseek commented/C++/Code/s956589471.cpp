#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    // Step 3: Declare variables to store input values
    int a, b, c, d, e, k;

    // Step 4: Read input values from the user
    cin >> a >> b >> c >> d >> e >> k;

    // Step 5: Calculate the difference between e and a and check if it is less than or equal to k
    cout << (e - a <= k ? "Yay!" : ":(") << endl;

    // Step 7: Return 0 to indicate successful execution
    return 0;
}
