
package main // Import the necessary package for input and output operations

import "fmt" // Import the necessary package for input and output operations

func main() { // The main function is the entry point of the program
  	var str string // Declare a string variable named str
  	fmt.Scanln(&str) // Input the string from the user and store it in the string variable str
  	if str[2] == str[3] && str[4] == str[5] { // Check if the characters at positions 2 and 3 are the same and if the characters at positions 4 and 5 are the same
  		fmt.Println("Yes") // Output "Yes"
  	} else {
  		fmt.Println("No") // Output "No"
  	}
}

