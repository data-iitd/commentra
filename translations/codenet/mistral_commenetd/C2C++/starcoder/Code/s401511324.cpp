#include<iostream> // Include the standard input/output library
using namespace std; // Use the standard namespace
int main(){ // Start of the main function
  int n, // Declare an integer variable 'n' to store the number of elements
      l[2001], // Declare an integer array 'l' of size 2001
      i, j, k, // Declare integer variables 'i', 'j', and 'k' for loop indices
      cnt=0, // Declare an integer variable 'cnt' and initialize it to zero
      tmp=0; // Declare an integer variable 'tmp' and initialize it to zero

  cin>>n; // Read an integer value from the standard input and store it in 'n'

  for(i=0; i<n; i++){ // Iterate through all elements of the array 'l'
    cin>>l[i]; // Read an integer value from the standard input and store it in the current index of 'l'
  }

  for(i=0; i<n-1; i++){ // Iterate through all elements except the last one in the array 'l'
    for(j=i+1; j<n; j++){ // Iterate through the remaining elements
      if(l[j]<l[i]){ // If the current element is smaller than the previous one
        tmp=l[i]; // Swap the current and previous elements
        l[i]=l[j];
        l[j]=tmp; // Update the array 'l' with the swapped elements
      }
    }
  }

  for(i=0; i<n-2; i++){ // Iterate through all elements except the last two in the array 'l'
    for(j=i+1; j<n-1; j++){ // Iterate through the remaining elements except the last one
      for(k=j+1; k<n; k++){ // Iterate through the remaining elements
        if(l[i]+l[j]>l[k]){ // Check if the sum of the first two elements is greater than the third one
          cnt++; // Increment the counter if the condition is true
        }
        else{ // If the condition is false, break out of the inner loop
          break;
        }
      }
    }
  }

  cout<<cnt<<endl; // Print the value of the counter to the standard output
  return 0; // End of the main function with a successful return status
}
