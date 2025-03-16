#include<iostream>  // Include the input-output stream library for standard input and output operations.
#include<vector>    // Include the vector library for using dynamic arrays.
#include<algorithm> // Include the algorithm library for using the sort function.

using namespace std; // Use the standard namespace to avoid prefixing standard library components with 'std::'.

int main(){ 
  int N; cin >> N; // Read the number of elements N from the standard input.
  vector<int> X(N); vector<int> Y(N); // Declare two vectors X and Y of size N to store the elements.
  
  // Read N elements into vector X and simultaneously copy them to vector Y.
  for(int i = 0; i < N; i++){ 
    cin >> X[i]; 
    Y[i] = X[i]; 
  }
  
  // Sort the vector Y in ascending order.
  sort(Y.begin(), Y.end());
  
  // Calculate the median of the sorted vector Y. The median is the middle element for odd N, and the average of the two middle elements for even N.
  int y = Y[N/2];
  
  // Iterate through each element in vector X and output the appropriate median value based on the comparison with y.
  for(int i = 0; i < N; i++){
    if(X[i] < y){
      cout << y; // If the element in X is less than the median, output the median.
    } else {
      cout << y - 1; // Otherwise, output the median minus one.
    }
    cout << endl; // Output a newline after each result.
  }
  
  return 0; // Return 0 to indicate successful execution.
}
