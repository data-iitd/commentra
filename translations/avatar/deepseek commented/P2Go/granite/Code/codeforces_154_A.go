
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	s := readString()  // Taking input string s
	n := readInt()  // Taking integer input n
	ans := 0  // Initializing the answer variable to 0

	// Loop runs n times
	for i := 0; i < n; i++ {
		x := readString()  // Taking input for string x of length 2
		a, b := 0, 0  // Initializing counters a and b to 0

		// Iterating over each character in the string s
		for j := 0; j < len(s); j++ {
			if string(s[j]) == string(x[0]) {  // Checking if the character matches the first character of x
				a++  // Incrementing the count for the first character
			} else if string(s[j]) == string(x[1]) {  // Checking if the character matches the second character of x
				b++  // Incrementing the count for the second character
			} else {  // If the character does not match any of the two
				ans += min(a, b)  // Adding the minimum of a and b to ans
				a, b = 0, 0  // Resetting the counters a and b to 0
			}
		}

		ans += min(a, b)  // Adding the minimum of a and b to ans after the inner loop
	}

	fmt.Println(ans)  // Printing the final answer
}

func readString() string {  // Function to read a string from input
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func readInt() int {  // Function to read an integer from input
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func min(a, b int) int {  // Function to find the minimum of two integers
	if a < b {
		return a
	}
	return b
}

