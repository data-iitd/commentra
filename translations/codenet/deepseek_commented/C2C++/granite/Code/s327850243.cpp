
#include<iostream>
using namespace std;
int main(){
 int m,n; // Declare variables to store the dimensions of matrix A and vector B
 int i,j; // Declare loop variables
 int A[100][100]; // Declare a 2D array to store matrix A
 int B[100]; // Declare an array to store vector B
 int S[100]={0}; // Declare an array to store the result of matrix multiplication

 cin>>m>>n; // Read the dimensions of matrix A and vector B

 // Read the elements of matrix A row by row
 for(i=0;i<m;i++){
   for(j=0;j<n-1;j++){
     cin>>A[i][j];
   }
   cin>>A[i][n-1]; // Read the last element of the row with a newline character
 }

 // Read the elements of vector B
 for(i=0;i<n;i++){
   cin>>B[i];
 }

 // Perform matrix multiplication of A and B and store the result in array S
 for(i=0;i<m;i++){
   for(j=0;j<n;j++){
     S[i]=S[i]+A[i][j]*B[j];
   }
 }

 // Print the elements of array S
 for(i=0;i<m;i++){
   cout<<S[i]<<endl;
 }

return 0;

}
