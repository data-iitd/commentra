package main

import "fmt"

func main() {
	// Declare a 3x3 matrix to store the input
	var input [4][4]int

	// Read the 3x3 matrix from the user
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			fmt.Scanf("%d", &input[i][j])
		}
	}

	// Read the number of test cases
	var tc int
	fmt.Scanf("%d", &tc)

	// Variable to store the current test case
	var testcase int

	// Loop through each test case
	for i := 0; i < tc; i++ {
		// Read the test case value
		fmt.Scanf("%d", &testcase)

		// Loop through the matrix to zero out the corresponding elements
		for i := 0; i < 3; i++ {
			for j := 0; j < 3; j++ {
				if input[i][j] == testcase {
					input[i][j] = 0
				}
			}
		}
	}

	// Check for winning conditions for a Tic-Tac-Toe game
	if input[0][0] == 0 && input[1][1] == 0 && input[2][2] == 0 {
		fmt.Println("Yes")
	} else if input[0][2] == 0 && input[1][1] == 0 && input[2][0] == 0 {
		fmt.Println("Yes")
	} else if input[0][0] == 0 && input[0][1] == 0 && input[0][2] == 0 {
		fmt.Println("Yes")
	} else if input[1][0] == 0 && input[1][1] == 0 && input[1][2] == 0 {
		fmt.Println("Yes")
	} else if input[2][0] == 0 && input[2][1] == 0 && input[2][2] == 0 {
		fmt.Println("Yes")
	} else if input[0][0] == 0 && input[1][0] == 0 && input[2][0] == 0 {
		fmt.Println("Yes")
	} else if input[0][1] == 0 && input[1][1] == 0 && input[2][1] == 0 {
		fmt.Println("Yes")
	} else if input[0][2] == 0 && input[1][2] == 0 && input[2][2] == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

