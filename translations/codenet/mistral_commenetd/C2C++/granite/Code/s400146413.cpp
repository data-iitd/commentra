

#include<iostream>

// Function to perform linear search on an array
int linearsearch(int S[], int n, int key){
  int i = 0; // Initialize index variable i to 0
  int count = 0; // Initialize count variable to 0

  // Search for the key in the array S until it is found or the end of the array is reached
  while( S[i]!= key ){
    i++; // Increment i by 1 for each iteration
    if( i >= n ){ // Check if the end of the array has been reached
      count = 1; // Set count to 1 if key is not found in the array
      return count; // Return count to the calling function
    }
  }

  // If key is found, return 0 to indicate that it was found
  return 0;
}

// Main function to read input and call linearsearch function
int main(){
  int i, j, n, q, S[10000], T[10000]; // Declare and initialize variables
  int count = 0; // Initialize count variable to 0

  // Read the size of the array S from the user
  std::cout << "Enter the size of the array S: ";
  std::cin >> n;

  // Read the elements of array S from the user
  std::cout << "Enter " << n << " integers for array S:\n";
  for(i = 0; i < n; i++){
    std::cout << "Enter integer S[" << i << "]: ";
    std::cin >> S[i];
  }

  // Read the number of queries from the user
  std::cout << "Enter the number of queries: ";
  std::cin >> q;

  // Read the elements of array T from the user
  std::cout << "Enter " << q << " integers for array T:\n";
  for(j = 0; j < q; j++){
    std::cout << "Enter integer T[" << j << "]: ";
    std::cin >> T[j];
  }

  // Call linearsearch function for each element of array T and increment count if key is not found
  for( j = 0; j < q; j++){
    key = T[j]; // Assign the current element of array T to key variable
    if(linearsearch(S, n, key) == 1){ // Call linearsearch function and check if count is 1 (key not found)
      count++; // Increment count if key is not found
    }
  }

  // Print the final count to the user
  std::cout << "Number of integers in array S that are not present in array T: " << count << std::endl;

  // Return 0 to indicate successful execution of the program
  return 0;
}

