package main

import (
	"fmt"
)

func main() {
	var input [4][4]int
	var tc int

	// Use a nested for loop to read the elements of the `input` array from the standard input.
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			fmt.Scan(&input[i][j])
			// Read the elements of the input array
		}
	}
	fmt.Scan(&tc)
	// Read the number of test cases `tc` from the standard input.
	var testcase int
	// Use another nested for loop to iterate through each test case and check if the given testcase is present in the `input` array or not. If present, we set its value to 0.
	for i := 0; i < tc; i++ {
		fmt.Scan(&testcase)
		for m := 0; m < 3; m++ {
			for n := 0; n < 3; n++ {
				if input[m][n] == testcase {
					input[m][n] = 0
					// If the given testcase is present in the input array, set its value to 0.
				}
			}
		}
	}
	// Check if all the elements of any of the three 1x1 sub-arrays are 0 or not.
	if input[0][0] == 0 && input[1][1] == 0 && input[2][2] == 0 {
		fmt.Println("Yes")
		// If yes, print "Yes" and exit the program.
		return
	} else if input[0][2] == 0 && input[1][1] == 0 && input[2][0] == 0 {
		fmt.Println("Yes")
		// If yes, print "Yes" and exit the program.
		return
	} else if input[0][0] == 0 && input[0][1] == 0 && input[0][2] == 0 {
		fmt.Println("Yes")
		// If yes, print "Yes" and exit the program.
		return
	} else if input[1][0] == 0 && input[1][1] == 0 && input[1][2] == 0 {
		fmt.Println("Yes")
		// If yes, print "Yes" and exit the program.
		return
	} else if input[2][0] == 0 && input[2][1] == 0 && input[2][2] == 0 {
		fmt.Println("Yes")
		// If yes, print "Yes" and exit the program.
		return
	} else if input[0][0] == 0 && input[1][0] == 0 && input[2][0] == 0 {
		fmt.Println("Yes")
		// If yes, print "Yes" and exit the program.
		return
	} else if input[0][1] == 0 && input[1][1] == 0 && input[2][1] == 0 {
		fmt.Println("Yes")
		// If yes, print "Yes" and exit the program.
		return
	} else if input[0][2] == 0 && input[1][2] == 0 && input[2][2] == 0 {
		fmt.Println("Yes")
		// If yes, print "Yes" and exit the program.
		return
	} else {
		fmt.Println("No")
		// If none of the above conditions are satisfied, print "No" and exit the program.
		return
	}
}
