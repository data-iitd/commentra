#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  int sq[10000], fr[5000]; // Declare arrays to store squares and frequencies
  vector<int> com; // Declare vector to store unique squares
  int tmp; // Temporary variable for calculations

  while(1):
    cin >> n; // Read input integer n
    if(!n) break; // Break the loop if n is 0

    for(int i=1; i<n; i++) sq[i] = (i*i) % n; // Calculate squares modulo n
    com.clear(); // Clear the vector com to store new unique squares

    for(int i=1; i<n; i++){ // Find unique squares modulo n
      bool f = true; // Flag to check if the square is unique
      for(int j=0; j<com.size(); j++){
	if(com[j] == sq[i]){ // Check if the square is already in com
	  f = false; // Set flag to false if not unique
	  break; // Break the loop if not unique
	}
      }
      if(f) com.push_back(sq[i]); // Add unique square to com if flag is true
    }

    for(int i=0; i<=(n-1)/2; i++) fr[i] = 0; // Initialize frequency array

    for(int i=0; i<com.size(); i++){ // Calculate differences between unique squares
      for(int j=0; j<com.size(); j++){
	if(i != j): # Avoid comparing a square with itself
	  tmp = com[i] - com[j]; # Calculate difference
	  if(tmp < 0) tmp += n; # Adjust if tmp is negative
	  if(tmp > (n-1)/2) tmp = n - tmp; # Adjust if tmp is greater than half of n
	  fr[tmp]++; # Increment the count for the difference
	}
      }
    }

    for(int i=1; i<=(n-1)/2; i++) cout << fr[i] << endl; # Output the frequencies
  }
}

