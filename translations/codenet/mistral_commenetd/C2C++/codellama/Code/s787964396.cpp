#include<iostream>
#include<cstdlib>
#define I 10000

// Main function starts here
int main(){
  // Declare pointers 'a' and 'b' of integer type and allocate memory for them
  int *a, *b;
  int i, max = 0, n;

  // Read the number of elements 'n' from the user
  std::cout<<"Enter the number of elements: ";
  std::cin>>n;

  // Allocate memory for arrays 'a' and 'b' of size (n+1)
  a = (int *)malloc((n+1) * sizeof(int));
  b = (int *)malloc((n+1) * sizeof(int));

  // Read elements of array 'a' from the user
  std::cout<<"Enter "<<n<<" integers:\n";
  for(i = 0; i < n; i++){
    std::cin>>a[i+1];
    // Update the maximum element if a new element is greater
    if(a[i+1] > max) max = a[i+1];
  }

  // Call the CountingSort function to sort the array 'a' using counting sort algorithm
  CountingSort(a, b, n);

  // Print the sorted elements of array 'b'
  std::cout<<b[1];
  for(i = 2; i < n+1; i++)std::cout<<" "<<b[i];
  std::cout<<"\n";

  // Free the allocated memory for arrays 'a' and 'b'
  free(a);
  free(b);

  // Main function ends here
  return 0;
}

// Function to perform counting sort algorithm
void CountingSort(int a[], int b[], int k){
  // Declare an array 'c' of size I to store the count of occurrences of each element
  int c[I], i, j;

  // Initialize all elements of array 'c' to zero
  for(i = 0; i <= I; i++)c[i] = 0;

  // Count the occurrences of each element in array 'a' and store it in array 'c'
  for(j = 0; j < k; j++)c[a[j+1]]++;

  // Calculate the cumulative sum of all elements in array 'c'
  for(i = 1; i < I+1; i++)c[i] += c[i-1];

  // Sort the array 'b' by placing each element 'a[j]' at its correct position in array 'b'
  for(j = k; j > 0; j--){
    b[c[a[j]]] = a[j];
    c[a[j]]--;
  }
}

