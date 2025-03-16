#include <iostream>
using namespace std;

int main()
{
  int n,r,p,c; // Declare variables n, r, p, c of type int
  int i,j,k,l; // Declare variables i, j, k, l of type int
  int a[51],b[51]; // Declare arrays a and b of size 51

  // An infinite loop until the user inputs 0 for both n and r
  while( 1 ){
    cin>>n>>r; // Read the values of n and r from the standard input
    if(!n &&!r ) // Check if both n and r are 0
      break; // If yes, break out of the loop

    // Initialize array a with values from 1 to n
    for( i=0;i<n;i++)
      a[i]=i+1;

    // Iterate r times
    for( i=0;i<r;i++){
      cin>>p>>c; // Read the values of p and c from the standard input

      // Initialize array b with elements from array a
      for( j=0;j<c;j++)
	b[j] = a[n-p-c+1+j];

      // Shift elements of array a to the left by p-1 positions
      for( j=0;j<p-1;j++)
	a[n-p+j+1] = a[n-p+j];

      // Copy elements from array b to the end of array a
      for( j=n-p-c+1,k=0;k<c;j++,k++){
	a[j] = b[k];
      }

      // Print the last element of array a
      cout<<a[n-1]<<endl;
    }
  }
  return 0;
}
