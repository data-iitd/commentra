#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, n, ans;
    scanf("%d", &n); // Step 4: Read the input value for `n`
    int *p = (int *)malloc(n * sizeof(int)); // Step 5: Create a vector `p` of size `n`
    for(i = 0; i < n; i++){ // Step 6: Read values into the vector `p`
        scanf("%d", &p[i]);
    }
    ans = 0; // Step 7: Initialize `ans` to 0
    for(i = 0; i < n - 1; i++){ // Step 8: Loop through the vector `p`
        if(p[i] == i + 1){ // If the current element `p[i]` is equal to `i+1`
            p[i + 1] = p[i]; // Set the next element `p[i+1]` to `p[i]`
            ans += 1; // Increment `ans`
        }
    }
    if(p[n - 1] == n){ // Step 9: Check the last element
        ans += 1; // Increment `ans` if the last element is equal to `n`
    }
    printf("%d\n", ans); // Step 10: Output the result
}
