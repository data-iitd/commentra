#include <stdio.h>

int main(void){
  
  int N; // Declare an integer variable to store the number of elements
  scanf("%d", &N ); // Read the value of N from the standard input
  
  int i; // Declare an integer variable i
  long long sum = 0; // Initialize sum to store the sum of elements
  long long wa = 0; // Initialize wa to store the weighted sum
  int A[N]; // Declare an array A of size N to store the elements
  int sa[N]; // Declare an array sa of size N to store the differences between consecutive elements
  int ans; // Declare an integer variable ans to store the result
  int shou; // Declare an integer variable shou to store the quotient
  long long min = 1123456789; // Initialize min to store the minimum value
  
  // Use a for loop to read the elements of the array A and calculate the sum and wa
  for( i = 0; i < N; i++ ){
    scanf("%d", A+i); // Read the elements of the array A
    sum += A[i]; // Add the current element to sum
    wa += i+1; // Add the current index+1 to wa
  }
  
  // Check if the sum is divisible by wa
  if( sum % wa ) ans = 0; // If not, set ans to 0
  else{
    shou = sum/wa; // Calculate the quotient shou
    // Calculate the differences between consecutive elements and store them in the array sa
    for( i = 0; i < N; i++ ){
      sa[i] = A[(i+1)%N] - A[i]-shou;
    }
    
    // Check if all differences are less than or equal to 0 and divisible by N
    for( i = 0; i < N-1; i++ ){    
      if( sa[i] <= 0 && !(sa[i] % N))
        ans = 1; // If so, set ans to 1
      else{
        ans = 0; // Otherwise, set ans to 0 and break the loop
        break;
      }
    }
  }  
  
  // Print "YES" if ans is 1, otherwise print "NO"
  if( ans ) puts("YES");
  else{     puts("NO");}
  
  return 0; // Return 0 to indicate successful execution
}