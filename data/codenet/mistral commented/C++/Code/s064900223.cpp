
#include <iostream>
#include <vector>
using namespace std;

// Declare the main function
int main(){
 int i, n, ans; // Declare variables i, n, and ans

 // Read the number of elements in the vector from the user
 cin >> n; // Read the size of the vector

 // Allocate memory for the vector p of size n
 vector <int> p(n); // Initialize an empty vector p of size n

 // Read elements of the vector p from the user
 for(i=0;i<n;i++){ // Loop through each element of the vector p
 cin >> p[i]; // Read the value of the current element
 }

 // Initialize the answer variable ans to zero
 ans = 0;

 // Check each element of the vector p starting from the first one
 for(i=0;i<n-1;i++){ // Loop through each element except the last one
 if(p[i]==i+1){ // Check if the current element is equal to its index + 1
 p[i+1] = p[i]; // Swap the current element with the next one if it is in the wrong position
 ans +=1; // Increment the answer if a swap was made
 }
 }

 // Check the last element of the vector p
 if(p[n-1] == n){ // Check if the last element is equal to its index + 1
 ans +=1; // Increment the answer if it is in the wrong position
 }

 // Print the answer to the user
 cout << ans <<endl; // Output the answer
}