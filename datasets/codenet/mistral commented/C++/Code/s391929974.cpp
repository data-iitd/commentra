#include<iostream>
#include<vector>
using namespace std;

int main(){
  // Declare variables
  int n;                       // Number of elements in the array
  int sq[10000];               // Square array to store squares of numbers from 1 to n-1
  int fr[5000];                // Frequency array to store the frequency of each difference between squares
  vector<int> com;             // Vector to store unique squares
  int tmp;                     // Temporary variable

  // Start of the infinite loop
  while(1){
    cin >> n;                 // Read the number of elements in the array from the user
    if(!n)break;              // If the number is zero, break the loop

    // Initialize square array
    for(int i=1;i<n;i++)sq[i] = (i*i)%n;
    com.clear();              // Clear the vector before filling it with new unique squares

    // Find unique squares and store them in the vector
    for(int i=1;i<n;i++){
      bool f = true;           // Flag to check if the square is already present in the vector
      for(int j=0;j<com.size();j++){
	if(com[j]==sq[i]){       // If the square is already present, set the flag to false
	  f = false;
	  break;
	}
      }
      if(f)com.push_back(sq[i]); // If the square is not present, add it to the vector
    }

    // Initialize frequency array
    for(int i=0;i<=(n-1)/2;i++)fr[i] = 0;

    // Find the frequency of each difference between unique squares
    for(int i=0;i<com.size();i++){
      for(int j=0;j<com.size();j++){
	if(i!=j){                 // If the indices are not same
	  tmp = com[i]-com[j];    // Calculate the difference between two squares
	  if(tmp<0)tmp+=n;        // If the difference is negative, make it positive by adding n
	  if(tmp>(n-1)/2)tmp = n - tmp; // If the difference is greater than half the size of the array, make it smaller by subtracting the difference from the size of the array
	  fr[tmp]++;             // Increment the frequency of the difference
	}
      }
    }

    // Print the frequency of each difference
    for(int i=1;i<=(n-1)/2;i++)cout << fr[i] << endl;
  }
}
