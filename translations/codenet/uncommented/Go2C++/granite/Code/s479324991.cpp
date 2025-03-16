
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<double> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    double prev = arr[0];
    for (int i = 1; i < n; i++) {
        prev = (prev + arr[i]) / 2;
    }
    printf("%.10lf\n", prev);
    return 0;
}

