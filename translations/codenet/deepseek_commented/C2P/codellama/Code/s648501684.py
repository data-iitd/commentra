#include <stdio.h>

int main()
{
   # Declare variables to store the input values
   long int n, k, q;
   
   # Read three long integers from the standard input
   scanf("%ld%ld%ld", &n, &k, &q);
   
   # Declare an array of size n initialized to 0
   int arr[n];
   for(long int i=0; i<=n; i++) {
       arr[i] = 0; # Initialize each element to 0
   }
   
   # Read q integers and increment the corresponding index in the array arr
   for(long int i=0; i<q; i++) {
       long int temp;
       scanf("%ld", &temp);
       arr[temp] += 1;
   }
   
   # Check if the value at each index in arr is greater than q-k
   for(long int i=1; i<=n; i++) {
       if(arr[i]>(q-k)) {
           printf("Yes\n"); # Print "Yes" if the condition is met
       } else {
           printf("No\n"); # Print "No" otherwise
       }
   }

   return 0;
}

