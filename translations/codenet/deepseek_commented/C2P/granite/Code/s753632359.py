
#include<stdio.h>

int main(void){
   int N, D; /* N, Dは1以上20以下の integers */
   int ans, rem;

   # Read two integers from standard input
   N, D = map(int, input().split())

   # Calculate the number of groups that can be formed
   ans = N // (D*2+1)
   rem = N % (D*2+1)

   # If there are remaining items, increment the number of groups
   if rem!= 0:
       ans = ans + 1

   # Print the result to standard output
   print(ans)

   return 0;
}

