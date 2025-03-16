#include <iostream> // We include the standard input/output library

int main(){ // The main function is the entry point of the program
  int n; // An integer variable named 'n' to store the number of inputs
  int fd[6] = {}; // An integer array named 'fd' of size 6, initialized with zeros
  double height; // A double precision floating point variable named 'height' to store the height of a person
  int i, j; // Two integer variables named 'i' and 'j' used for looping

  std::cin >> n; // Read an integer value from the standard input and store it in the variable 'n'
  while(n--){ // Decrement the value of 'n' and as long as it is not zero, execute the following block of code
    std::cin >> height; // Read a floating point value from the standard input and store it in the variable 'height'
    if(height >= 185.0) fd[5]++; // If the height is greater than or equal to 185 cm, increment the value of the sixth element of the 'fd' array
    else if(height >= 180.0) fd[4]++; // Else if the height is greater than or equal to 180 cm, increment the value of the fifth element of the 'fd' array
    else if(height >= 175.0) fd[3]++; // Else if the height is greater than or equal to 175 cm, increment the value of the fourth element of the 'fd' array
    else if(height >= 170.0) fd[2]++; // Else if the height is greater than or equal to 170 cm, increment the value of the third element of the 'fd' array
    else if(height >= 165.0) fd[1]++; // Else if the height is greater than or equal to 165 cm, increment the value of the second element of the 'fd' array
    else fd[0]++; // Else, increment the value of the first element of the 'fd' array
  }

  for(i = 0;i < 6;i++){ // Iterate through the 'fd' array using a for loop
    std::cout << i + 1 << ":"; // Print the index of the current element of the array followed by a colon
    for(j = 0;j < fd[i];j++) // Iterate through the number of occurrences of the current element in the array
      std::cout << '*'; // Print a star for each occurrence
    std::cout << std::endl; // Print a newline character after each group of stars
  }
  return 0; // The main function returns zero to indicate successful execution
}

