package main

import (
	"fmt"
	"os"
)

func solve(tc int) {
	var a int
	// Read an integer input from standard input
	_, err := fmt.Fscan(os.Stdin, &a)
	if err != nil {
		return
	}
	// Print 1 if the input is 0, otherwise print 0
	if a == 0 {
		fmt.Println(1)
	} else {
		fmt.Println(0)
	}
}

func main() {
	tcs := 1
	tc := 1

	// Enter a loop that continues as long as the current test case number is less than or equal to the total number of test cases
	for tc <= tcs {
		solve(tc)
		tc++
	}
}

// <END-OF-CODE>
