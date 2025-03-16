#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  // Declare variables for processing
  int i, j, k, L, tmp, d, def, end, aj, max, min;

  // Infinite loop to continuously process input until a break condition is met
  for(;;){
    // Arrays to hold digits and intermediate values
    std::vector<int> an;
    std::vector<int> a1(6);
    std::vector<int> a2(6);
    
    // Read the initial number and the length of digits
    std::cin >> an[0] >> L;
    
    // Break the loop if the length L is zero
    if(!L) break;
    
    // Initialize aj with the first number and set end flag to 0
    aj = an[0]; 
    end = 0;

    // Loop to process up to 20 iterations
    for(k = 1; k < 21; k++){
      // Extract digits of aj into a1 and a2 arrays
      for(i = L - 1; i >= 0; i--, aj /= 10){
        a1[i] = aj % 10; // Store digit in a1
        a2[i] = aj % 10; // Store digit in a2
      }

      // Sort a1 in ascending order and a2 in descending order
      std::sort(a1.begin(), a1.end());
      std::sort(a2.begin(), a2.end(), std::greater<int>());

      // Initialize variables for max and min calculations
      d = 1; 
      max = 0; 
      min = 0;

      // Construct the max and min numbers from sorted digits
      for(i = L - 1; i >= 0; i--, d *= 10){
        max += a1[i] * d; // Construct max number
        min += a2[i] * d; // Construct min number
      }

      // Calculate the difference
      def = max - min;

      // Check if the difference is already in the an array
      for(i = 0; i < k; i++){
        if(def == an[i]){
          // If found, print the index, difference, and the number of iterations
          std::cout << i << " " << def << " " << k - i << std::endl;
          end = 1; // Set end flag to break the loop
          break;
        }
      }

      // If a match was found, exit the loop
      if(end == 1) break;

      // Store the new difference in the an array and update aj
      an.push_back(def); 
      aj = def;
    }
  }
    
  return 0; // Return success
}
