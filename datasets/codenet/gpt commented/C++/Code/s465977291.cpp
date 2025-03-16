#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;

// Define a type alias for long long to simplify code
typedef long long ll;

int main() {
    // Declare variables for the number of items (n) and the distance (d)
    int n, d;
    
    // Read input values for n and d from the user
    cin >> n >> d;

    // Calculate the effective range of coverage, which is (d*2 + 1)
    double a = d * 2 + 1;

    // Calculate and output the minimum number of groups needed to cover 'n' items
    // This is done by dividing 'n' by the coverage 'a' and rounding up to the nearest whole number
    cout << ceil(n / a) << endl;

    return 0; // End of the program
}
