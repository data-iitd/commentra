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
    
    # Step 1: Input the number of elements (n) and the array elements (a[100])
    n = int(input())
    for i in range(n):
        a[i] = int(input())
        avg += a[i]
    
    # Step 2: Calculate the average of the array elements
    avg /= n
    
    # Step 3: Find the element closest to the average
    s = abs(a[0] - avg)
    ans = 0
    for i in range(1, n):
        if s > abs(a[i] - avg):
            s = abs(a[i] - avg)
            ans = i
    
    # Step 4: Output the index of the closest element
    print(ans)
    return 0
}
