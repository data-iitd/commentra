#include<stdio.h>  // Include the input-output stream library
#include<stdlib.h> // Include the standard library
#include<string.h> // Include the string library
#include<math.h>   // Include the math library
#include<stdbool.h>// Include the boolean library

int main(){
    int n;
    scanf("%d", &n);  // Read the integer n
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);  // Read n integers into the vector a
    }

    int ans=0;  // Initialize ans to 0
    bool ok = true;  // Initialize ok to true
    while(ok){  // Start the main loop
        for(int i=0;i<n;i++){  // Iterate over each element in the vector a
            if(a[i]%2 == 1){  // Check if the element is odd
                printf("%d\n", ans);  // Print the current value of ans and exit
                return 0;
            }
            else{  // If the element is even
                a[i] /= 2;  // Divide the element by 2
            }
        }
        ans++;  // Increment ans after processing all elements
    }

    printf("%d\n", ans);  // Print the final value of ans
}

