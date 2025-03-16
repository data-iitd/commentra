#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

// Declare arrays to store input values, prefix sums, and suffix sums
long long a[200005];
long long pre[200005];
long long last[200005];

int main() {
    int n;
    // Read the number of elements
    scanf("%d", &n);
    
    // Read the input values into the array 'a'
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    long long sumpre = 0, sumlast = 0;

    // Calculate prefix sums and store them in 'pre' array
    for(int i = 1; i < n; i++) {
        sumpre = sumpre + a[i];
        pre[i] = sumpre;
        // Debugging output for prefix sums (commented out)
        // printf("%lld++\n", pre[i]);
    }

    // Calculate suffix sums and store them in 'last' array
    for(int i = n; i > 1; i--) {
        sumlast = sumlast + a[i];
        last[i] = sumlast;
        // Debugging output for suffix sums (commented out)
        // printf("%lld+++\n", last[i]);
    }

    // Initialize 'd' to a large value to find the minimum difference
    long long d = (1ll << 60);

    // Calculate the minimum absolute difference between prefix and suffix sums
    for(int i = 1; i < n; i++) {
        // Debugging output for the difference calculation (commented out)
        // printf("%lld\n", pre[i] - last[i + 1]);
        d = min(d, abs(pre[i] - last[i + 1]));
    }

    // Output the minimum difference found
    printf("%lld\n", d);
}
