#include<iostream>
using namespace std;

// Declare variables N and D of integer type
// N and D should be positive integers less than or equal to 20
int main(){
   int N, D;

   // Initialize variables N and D using cin function
   cin >> N >> D;

   // Calculate the quotient of N by (D*2+1) and store it in variable ans
   int ans;
   ans = N / (D*2+1);

   // Calculate the remainder of N by (D*2+1) and store it in variable rem
   int rem;
   rem = N % (D*2+1);

   // Check if the remainder is zero or not
   if(rem != 0){
       // If the remainder is not zero, increment the value of ans by 1
       ans = ans + 1;
   }

   // Print the value of ans using cout function
   cout << ans << endl;

   // Return 0 to indicate successful execution of the program
   return 0;
}

