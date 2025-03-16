
#include <bits/stdc++.h>
using namespace std;

// Define helper functions
#define input() cin
#define ceil(a, b) ((a)+(b)-1)/(b)
#define round(x) ((x)<0?(x)-0.5:((x)>0?(x)+0.5:(x)))
#define fermat(x, y, MOD) (pow((x), (y), (MOD)) + (MOD) - 1) % (MOD)
#define lcm(x, y) ((x)*(y))/gcd((x), (y))
#define lcm_list(nums) (reduce(lcm, (nums).begin(), (nums).end(), 1))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Read input
    int q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;

    // Calculate the length of the longest segment that can be formed
    int best1L = min(q*4, min(h*2, s));
    int best2L = min(d, best1L*2);

    // Check if n is even
    if (n % 2 == 0) {
        // If it is, print the length of the longest segment that can be formed
        // by dividing n into pairs and using the best2L length for each pair
        cout << best2L * (n/2) << endl;
    } else {
        // If n is odd, print the length of the longest segment that can be formed
        // by dividing n-1 into pairs and using the best2L length for each pair,
        // and adding the best1L length at the end
        cout << best2L * (n/2) + best1L << endl;
    }

    return 0;
}

