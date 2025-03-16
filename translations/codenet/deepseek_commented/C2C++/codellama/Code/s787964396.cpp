#include<iostream>
#include<cstdlib>

#define I 10000 // Define a constant I with the value 10000

using namespace std;

// Function to perform Counting Sort
void CountingSort(int*, int*, int);

int main(){
  int *a, *b, i, max = 0, n;
  
  // Read the number of elements
  cin >> n;
  
  // Dynamically allocate memory for arrays a and b
  a = (int *)malloc((n + 1) * sizeof(int));
  b = (int *)malloc((n + 1) * sizeof(int));
  
  // Read elements into array a starting from index 1 to n
  for(i = 0; i < n; i++){
    cin >> a[i + 1];
  }
  
  // Call CountingSort function to sort the array
  CountingSort(a, b, n);
  
  // Print the sorted elements starting from index 1 to n
  cout << b[1];
  for(i = 2; i < n + 1; i++) cout << " " << b[i];
  cout << endl;
  
  // Free the allocated memory
  free(a);
  free(b);
  
  return 0;
}

// Function to perform Counting Sort
void CountingSort(int a[], int b[], int k){
  int c[I], i, j;
  
  // Initialize array c to store the count of each element
  for(i = 0; i <= I; i++) c[i] = 0;
  
  // Count the occurrences of each element in array a
  for(j = 0; j < k; j++) c[a[j + 1]]++;
  
  // Compute the cumulative count to determine the positions of elements in the sorted array
  for(i = 1; i < I + 1; i++) c[i] += c[i - 1];
  
  // Place elements into array b in sorted order
  for(j = k; j > 0; j--){
    b[c[a[j]]] = a[j];
    c[a[j]]--;
  }
}

