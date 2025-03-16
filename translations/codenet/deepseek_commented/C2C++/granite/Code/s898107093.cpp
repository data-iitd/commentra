
#include <string>  // Include string manipulation functions
#include <vector>  // Include vector container
#include <iostream>  // Include standard input/output functions

int main() {
  std::vector<std::string> t, h;  // Declare vectors to store Tarō and Hanako's strings
  int n, taro = 0, hanako = 0, i;  // Declare number of rounds, scores, and loop index
  std::cin >> n;  // Read the number of rounds

  // Loop through each round
  for (i = 0; i < n; i++) {
    std::string temp;  // Declare temporary string
    std::cin >> temp;  // Read Tarō's string
    t.push_back(temp);  // Add Tarō's string to the vector
    std::cin >> temp;  // Read Hanako's string
    h.push_back(temp);  // Add Hanako's string to the vector
    if (t[i] < h[i]) hanako += 3;  // Compare and update Hanako's score
    if (t[i] > h[i]) taro += 3;  // Compare and update Tarō's score
    if (t[i] == h[i]) {  // If strings are equal
      taro += 1;  // Increment Tarō's score by 1
      hanako += 1;  // Increment Hanako's score by 1
    }
  }

  std::cout << taro << " " << hanako << std::endl;  // Print the final scores
  return 0;  // Return 0 to indicate successful execution
}

