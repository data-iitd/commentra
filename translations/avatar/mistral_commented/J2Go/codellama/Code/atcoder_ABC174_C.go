
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declaring static variables for BufferedReader and PrintWriter
	br := bufio.NewReader(os.Stdin)
	pw := bufio.NewWriter(os.Stdout)

	// Declaring a function to read an integer from the standard input
	readInt := func() int {
		// Function to read an integer from the standard input
		var st string
		fmt.Fscan(br, &st)
		return strconv.Atoi(st)
	}

	// Declaring a function to print the answer
	print := func(ans int) {
		// Function to print the answer
		fmt.Fprintln(pw, ans)
	}

	// Declaring a function to find the answer
	solve := func() int {
		// Function to find the answer
		K := readInt() // Reading the input value of K

		// Checking if K is even or multiple of 5, returning -1 if true
		if K%2 == 0 || K%5 == 0 {
			return -1
		}

		// If K is multiple of 7, dividing it by 7 and multiplying it by 9
		if K%7 == 0 {
			K /= 7
		}
		K *= 9

		// Initializing the answer variable and the remainder variable
		ans := 1
		remainder := 10 % K

		// Using a while loop to find the answer
		for remainder != 1 {
			ans++ // Incrementing the answer variable
			remainder = remainder*10 % K // Updating the remainder variable
		}

		// Returning the answer
		return ans
	}

	// Calling the solve function and printing the result
	print(solve())

	// Flushing the output buffer
	pw.Flush()
}

