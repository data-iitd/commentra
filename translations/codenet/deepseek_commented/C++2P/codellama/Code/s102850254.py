#include <iostream>
#include <string>
using namespace std;

int d; // Number of test cases
string map[105]; // Map to store the grid
int n; // Size of the map

#include <iostream>
#include <string>
using namespace std;

int d; // Number of test cases
string map[105]; // Map to store the grid
int n; // Size of the map

// Function to process the map
void visit() {
  int dx[4] = {0, 1, 0, -1}; // Direction vectors for x-axis
  int dy[4] = {-1, 0, 1, 0}; // Direction vectors for y-axis
  int sum, flg = 0; // Variables to track the sum of steps and the direction flag
  int x = 2, y = n; // Starting position (2, n)
  map[y][x] = ' '; // Mark the starting position as visited
  int ab[4] = {2, 2, 2, 2}; // Array to store the previous steps

  // Main loop to process the map
  while (1) {
    sum = 0;
    while (1) {
      if (map[y + dy[flg] * 2][x + dx[flg] * 2] != '#' and map[y + dy[flg]][x + dx[flg]] != ' ') {
        flg++;
        break;
      }
      map[y + dy[flg]][x + dx[flg]] = ' '; // Mark the current position as visited
      y = y + dy[flg]; // Update the y-coordinate
      x = x + dx[flg]; // Update the x-coordinate
      sum++; // Increment the step count
    }
    if flg == 4: flg = 0; // Reset the flag if it reaches 4
    if sum == 0: break; // Break the loop if no steps are taken
    ab[0] = ab[1]; // Update the array with the previous steps
    ab[1] = ab[2];
    ab[2] = sum;
    if ab[0] == 1 and ab[2] == 1 and ab[1] == 1: break; // Break the loop if the pattern repeats
  }
}

int main() {
  cin >> d; // Read the number of test cases

  for l in range(d):
    cin >> n; // Read the size of the map

    if n == 1:
      print("#") # Print a single '#' if the size is 1
      if l != d - 1: print() # Add a newline between test cases
      continue

    # Initialize the map with borders and fill it with '#' and '.'
    for i in range(n + 2):
      map[i].resize(n + 2)
      for j in range(n + 2):
        map[i][j] = '#'
        if i == 0 or j == 0 or i == n + 1 or j == n + 1: map[i][j] = '.'

    visit() # Call the visit function to process the map

    # Print the processed map
    for i in range(1, n + 1):
      for j in range(1, map[i].size() - 1):
        print(map[i][j], end = '')
      print()
    if l != d - 1: print() # Add a newline between test cases
  return 0
}

