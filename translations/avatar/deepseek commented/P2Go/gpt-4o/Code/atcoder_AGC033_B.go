package main

import (
	"fmt"
)

func main() {
	var H, W, N int
	fmt.Scan(&H, &W, &N) // Read the dimensions of the grid and the starting position
	var s_r, s_c int
	fmt.Scan(&s_r, &s_c) // Read the starting position of the robot
	var S, T string
	fmt.Scan(&S) // Read the string of movements for S
	fmt.Scan(&T) // Read the string of movements for T

	Judge := false // Initialize a flag to check if the robot is out of bounds
	S_L, S_R, S_U, S_D := 0, 0, 0, 0 // Initialize counters for movements in each direction for S
	T_L, T_R, T_U, T_D := 0, 0, 0, 0 // Initialize counters for movements in each direction for T

	// Iterate through each movement in S
	for x := 0; x < N; x++ {
		switch S[x] {
		case 'L':
			S_L++
			if S_L-T_R-s_c == 0 { // Check if S is about to hit the left boundary
				Judge = true
			}
		case 'R':
			S_R++
			if s_c+(S_R-T_L) == W+1 { // Check if S is about to hit the right boundary
				Judge = true
			}
		case 'U':
			S_U++
			if S_U-T_D-s_r == 0 { // Check if S is about to hit the upper boundary
				Judge = true
			}
		case 'D':
			S_D++
			if s_r+(S_D-T_U) == H+1 { // Check if S is about to hit the lower boundary
				Judge = true
			}
		}

		// Update the counters for T based on its movements
		switch T[x] {
		case 'L':
			if S_R-T_L+s_c != 1 { // Check if T is about to move left
				T_L++
			}
		case 'R':
			if s_c+(T_R-S_L) != W { // Check if T is about to move right
				T_R++
			}
		case 'U':
			if S_D-T_U+s_r != 1 { // Check if T is about to move up
				T_U++
			}
		case 'D':
			if s_r+(T_D-S_U) != H { // Check if T is about to move down
				T_D++
			}
		}
	}

	// Check the flag and print the result
	if Judge {
		fmt.Println("NO") // Print 'NO' if the robot is out of bounds
	} else {
		fmt.Println("YES") // Print 'YES' if the robot is within bounds
	}
}

// <END-OF-CODE>
