#include <iostream>  // Include input/output stream functions
#include <string>  // Include string manipulation functions
#include <vector>  // Include vector container

int main() {
  std::vector<std::string*> t, h;  // Declare vectors for Tarō and Hanako's strings
  int n, taro = 0, hanako = 0, i;  // Declare number of rounds, scores, and loop index
  std::cin >> n;  // Read the number of rounds

  // Loop through each round
  for (i = 0; i < n; i++) {
    std::string *t_str = new std::string;  // Allocate memory for Tarō's string
    std::string *h_str = new std::string;  // Allocate memory for Hanako's string
    std::cin >> *t_str;  // Read Tarō's string
    std::cin >> *h_str;  // Read Hanako's string
    t.push_back(t_str);  // Add Tarō's string to the vector
    h.push_back(h_str);  // Add Hanako's string to the vector
    if (*t_str < *h_str) hanako += 3;  // Compare and update Hanako's score
    if (*t_str > *h_str) taro += 3;  // Compare and update Tarō's score
    if (*t_str == *h_str) {  // If strings are equal
      taro += 1;  // Increment Tarō's score by 1
      hanako += 1;  // Increment Hanako's score by 1
    }
  }

  std::cout << taro << " " << hanako << std::endl;  // Print the final scores

  // Free the memory allocated for Tarō's and Hanako's strings
  for (i = 0; i < n; i++) {
    delete t[i];
    delete h[i];
  }

  return 0;  // Return 0 to indicate successful execution
}
