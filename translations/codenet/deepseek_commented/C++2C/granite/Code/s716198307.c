
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<functional>

int main(void){
    int n, a[100];
    double avg = 0, s, ans;
    
    // Step 1: Input the number of elements (n) and the array elements (a[100])
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        avg += a[i];
    }
    
    // Step 2: Calculate the average of the array elements
    avg /= n;
    
    // Step 3: Find the element closest to the average
    s = fabs(a[0] - avg);
    ans = 0;
    for (int i = 1; i < n; i++) {
        if (s > fabs(a[i] - avg)) {
            s = fabs(a[i] - avg);
            ans = i;
        }
    }
    
    // Step 4: Output the index of the closest element
    printf("%.0f\n", ans);
    return 0;
}
