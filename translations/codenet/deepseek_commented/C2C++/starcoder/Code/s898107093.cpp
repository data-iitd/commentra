#include <iostream>  // Include standard input/output functions
#include <cstring>  // Include string manipulation functions
#include <cstdlib>  // Include memory allocation functions

using namespace std;  // Use standard namespace

int main() {
  char **t, **h;  // Declare pointers to pointers for Tarō and Hanako's strings
  int n, taro = 0, hanako = 0, i;  // Declare number of rounds, scores, and loop index
  cin >> n;  // Read the number of rounds
  t = new char*[n];  // Allocate memory for Tarō's strings
  h = new char*[n];  // Allocate memory for Hanako's strings

  // Loop through each round
  for (i = 0; i < n; i++) {
    t[i] = new char[100];  // Allocate memory for each Tarō's string
    h[i] = new char[100];  // Allocate memory for each Hanako's string
    cin >> t[i];  // Read Tarō's string
    cin >> h[i];  // Read Hanako's string
    if (strcmp(t[i], h[i]) < 0) hanako += 3;  // Compare and update Hanako's score
    if (strcmp(t[i], h[i]) > 0) taro += 3;  // Compare and update Tarō's score
    if (strcmp(t[i], h[i]) == 0) {  // If strings are equal
      taro += 1;  // Increment Tarō's score by 1
      hanako += 1;  // Increment Hanako's score by 1
    }
    delete[] t[i];  // Free the memory allocated for Tarō's string
    delete[] h[i];  // Free the memory allocated for Hanako's string
  }

  cout << taro << " " << hanako << endl;  // Print the final scores
  return 0;  // Return 0 to indicate successful execution
}

