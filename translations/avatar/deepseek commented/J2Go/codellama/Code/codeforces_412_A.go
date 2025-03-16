package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Reading the integer n from the user
	n, _ := strconv.Atoi(os.Args[1])
	// Reading the integer k from the user
	k, _ := strconv.Atoi(os.Args[2])
	// Reading the string a from the user
	a := os.Args[3]

	// Check if k is greater than n/2
	if k > n/2 {
		// Move right until k equals n
		for k < n {
			fmt.Println("RIGHT") // Print "RIGHT"
			k++                  // Increment k
		}
	} else {
		// Move left until k equals 1
		for k > 1 {
			fmt.Println("LEFT") // Print "LEFT"
			k--                 // Decrement k
		}
	}

	// If k equals 1, print each character of the string a starting from the first character and moving rightwards
	if k == 1 {
		for i := 0; i < len(a); i++ {
			fmt.Println("PRINT " + string(a[i])) // Print the character and then move right
			if i+1 < len(a) {
				fmt.Println("RIGHT") // Print "RIGHT" if it's not the last character
			}
		}
	} else {
		// If k does not equal 1, print each character of the string a starting from the last character and moving leftwards
		for i := len(a) - 1; i >= 0; i-- {
			fmt.Println("PRINT " + string(a[i])) // Print the character and then move left
			if i-1 >= 0 {
				fmt.Println("LEFT") // Print "LEFT" if it's not the first character
			}
		}
	}
}

