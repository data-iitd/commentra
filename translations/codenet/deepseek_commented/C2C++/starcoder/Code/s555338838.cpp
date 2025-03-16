#include <iostream>
using namespace std;

int main(){
  int key, i, j, len, a[101];
  
  // Step 1: Read the length of the array
  cin >> len;
  
  // Step 2: Read the elements of the array
  for(i = 0;i < len;i++) cin >> a[i];

  // Step 3: Perform Insertion Sort
  for(j = 1;j < len;j++){
    // Print the array before each iteration
    for(i = 0;i < len;i++) cout << (i!= 0? " " : "") << a[i];
    cout << endl;
    
    // Store the current element to be inserted
    key = a[j];
    
    // Shift elements to the right to make space for the key
    for(i = j - 1;i >= 0 && a[i] > key;i--) a[i + 1] = a[i];
    
    // Insert the key into the correct position
    a[i + 1] = key;
  }

  // Step 4: Print the sorted array
  for(i = 0;i < len;i++) cout << (i!= 0? " " : "") << a[i];
  cout << endl;
  return 0;
}
