#include<iostream>
using namespace std;

// Main function starts here
int main()
{

  int i,j,N, // Declare variables i, j, and N
      A[100], // Declare an array A of size 100
      tmp,    // Declare a temporary variable tmp
      count=0; // Initialize counter variable count to 0

  // Read the number of elements in the array from user input
  cin>>N;

  // Allocate memory for the array A and read its elements from user input
  for(i=0;i<N;i++){

    cin>>A[i]; // Read an element of the array A
  }

  // Perform bubble sort on the array A
  for(i=0;i<N-1;i++){

    for(j=N-1;j>i;j--){ // Iterate through the array from last to first

      if(A[j]<A[j-1]){ // Check if the current element is smaller than the previous one

	tmp=A[j]; // Swap the elements if they are in wrong order
	A[j]=A[j-1];
	A[j-1]=tmp;

	count++; // Increment the counter for each swap
      }
    }
  }

  // Print the sorted array A
  for(i=0;i<N;i++){

    cout<<A[i]; // Print an element of the array A

    if(i<N-1)cout<<" "; // Add a space between elements, except the last one

  }

  cout<<endl; // Print a newline character after the sorted array

  // Print the number of swaps (count) made during sorting
  cout<<count<<endl;

  // Main function ends here with a return value of 0
  return 0;
}

