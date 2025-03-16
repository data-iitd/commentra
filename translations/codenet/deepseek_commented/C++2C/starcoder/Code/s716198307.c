#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
    s = abs(a[0] - avg);
    ans = 0;
    for (int i = 1; i < n; i++) {
        if (s > abs(a[i] - avg)) {
            s = abs(a[i] - avg);
            ans = i;
        }
    }
    
    // Step 4: Output the index of the closest element
    printf("%d\n", ans);
    return 0;
}
