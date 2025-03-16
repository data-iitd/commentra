#include<iostream>
#include<cmath>
#include<complex>
#include<cstdlib>
#include<algorithm>
#include<functional>
using namespace std;

int main(void){
    int n, a[100];
    double avg = 0, s, ans;
    
    // Step 1: Input the number of elements (n) and the array elements (a[100])
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        avg += a[i];
    }
    
    // Step 2: Calculate the average of the array elements
    avg /= n;
    
    // Step 3: Find the element closest to the average
    s = abs(a[0] - avg);
    ans = 0;
    for (int i = 1; i < n; i++) {
        if (s > abs(a[i] - avg)) {
            s = abs(a[i] - avg);
            ans = i;
        }
    }
    
    // Step 4: Output the index of the closest element
    cout << ans << endl;
    return 0;
}
