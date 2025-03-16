#include<iostream>
using namespace std;

int main(){
  int a[3], b[3]; // Declare two arrays 'a' and 'b' of size 3
  int c[3][3]; // Declare a 3x3 matrix 'c'
  int i, j; // Declare two integer variables 'i' and 'j'

  // Initialize the matrix 'c' with user input
  for(i=0;i<3;i++){
    cout << "Enter the elements of row " << i+1 << ": ";
    cin >> c[i][0] >> c[i][1] >> c[i][2];
    // Scan the three elements of each row and store them in the matrix 'c'
  }

  // Initialize array 'a' with the first row of matrix 'c'
  a[0] = 0;
  for(i=0;i<3;i++){
    b[i] = c[0][i]; // Store the elements of the first row of matrix 'c' in array 'b'
  }

  // Initialize array 'a' with the difference between the corresponding elements of matrix 'c' and array 'b'
  for(i=1;i<3;i++){
    a[i] = c[i][0] - b[0]; // Subtract the first element of each row of matrix 'c' from the corresponding element of array 'b' and store the result in array 'a'
  }

  // Compare each element of matrix 'c' with the corresponding elements of array 'a' and 'b'
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      if(c[i][j] != a[i] + b[j]){ // Check if the element at position (i,j) in matrix 'c' is equal to the sum of the elements at position i in array 'a' and j in array 'b'
        cout << "No" << endl; // If not, print "No" and exit the program
        return 0;
      }
    }
  }

  // If all the elements in matrix 'c' match the condition, print "Yes"
  cout << "Yes" << endl;
  return 0;
}

