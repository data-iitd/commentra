#include <stdio.h>  // Include the standard input-output library
#include <stdlib.h> // Include the standard library

int main(){
    int n;
    scanf("%d", &n);  // Read the integer n
    int* a = (int*)malloc(n * sizeof(int));  // Allocate memory for n integers
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);  // Read n integers into the array a
    }

    int ans = 0;  // Initialize ans to 0
    int ok = 1;  // Initialize ok to 1 (true)
    while(ok){  // Start the main loop
        for(int i = 0; i < n; i++){  // Iterate over each element in the array a
            if(a[i] % 2 == 1){  // Check if the element is odd
                printf("%d\n", ans);  // Print the current value of ans and exit
                free(a);  // Free the allocated memory
                return 0;
            }
            else{  // If the element is even
                a[i] /= 2;  // Divide the element by 2
            }
        }
        ans++;  // Increment ans after processing all elements
    }

    printf("%d\n", ans);  // Print the final value of ans
    free(a);  // Free the allocated memory
}

