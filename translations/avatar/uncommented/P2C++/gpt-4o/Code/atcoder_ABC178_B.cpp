#include <iostream>
#include <algorithm>
using namespace std;

long long max_product(long long a, long long b, long long c, long long d) {
    return max({a * c, b * d, a * d, b * c});
}

int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max_product(a, b, c, d) << endl;
    return 0;
}

// <END-OF-CODE>
