package main

import (
	"fmt"
)

func main() {
	var n int // We declare an integer variable 'n' to store the number of elements in the strings
	var a, b, c string // We declare three string variables 'a', 'b', and 'c' to store the input strings
	ans := 0 // We initialize an integer variable 'ans' to 0 to store the answer

	fmt.Scan(&n) // We read the number of elements in the strings from the standard input
	fmt.Scan(&a, &b, &c) // We read the three strings 'a', 'b', and 'c' from the standard input, one string at a time

	for i := 0; i < n; i++ { // We start a for loop that iterates from 0 to 'n'-1
		if a[i] == b[i] && b[i] == c[i] { // We check if all three characters at the current index are equal
			// Do nothing
		} else if a[i] == b[i] || b[i] == c[i] || a[i] == c[i] { // We check if any two of the three characters are equal
			ans++ // If so, we increment the answer by 1
		} else { // If none of the above conditions are met, we increment the answer by 2
			ans += 2
		}
	}
	fmt.Println(ans) // We print the answer to the standard output
}

// <END-OF-CODE>
