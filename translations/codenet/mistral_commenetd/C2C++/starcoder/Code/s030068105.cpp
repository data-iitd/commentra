#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int n; // Declare an integer variable 'n' to store the number of elements
         // in the array

  int *data; // Declare a pointer 'data' to store the address of the first element
             // of the array

  // Read the number of elements from the user
  cout << "Enter the number of elements: ";
  cin >> n;

  // Allocate memory for the array of size 'n' using malloc()
  data = (int*)malloc(sizeof(int)*n);

  // Read each element of the array from the user
  for(int i=0; i<n; i++) {
    cout << "Enter element " << i+1 << ": ";
    cin >> data[i];
  }

  int max = 0; // Initialize'max' variable to store the maximum element
  int index; // Initialize 'index' variable to store the index of the maximum element

  // Find the maximum element and its index
  for(int i=0; i<n; i++) {
    if(data[i] > max) {
      max = data[i];
      index = i;
    }
  }

  int a = 0; // Initialize 'a' variable to store the sum of all elements except the maximum

  // Calculate the sum of all elements except the maximum
  for(int i=0; i<n; i++) {
    if(i!= index) a += data[i];
  }

  // Check if the sum of all elements except the maximum is greater than the maximum
  if(a > max) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  // Free the allocated memory
  free(data);

  // Return 0 to indicate successful execution of the program
  return 0;
}
