package main

import (
	"fmt"
)

func main() {
	// Initialize variables
	var H, W, N int
	fmt.Scan(&H, &W, &N)
	var s_r, s_c int
	fmt.Scan(&s_r, &s_c)
	var S, T string
	fmt.Scan(&S)
	fmt.Scan(&T)

	Judge := false

	// Initialize variables for string S
	S_L, S_R, S_U, S_D := 0, 0, 0, 0

	// Iterate through string S
	for x := 0; x < N; x++ {
		// Check current character in S
		switch S[x] {
		case 'L':
			S_L++
			// Check condition for 'L'
			if S_L-S_R-s_c == 0 {
				Judge = true
			}
		case 'R':
			S_R++
			// Check condition for 'R'
			if s_c+(S_R-S_L) == W+1 {
				Judge = true
			}
		case 'U':
			S_U++
			// Check condition for 'U'
			if S_U-S_D-s_r == 0 {
				Judge = true
			}
		case 'D':
			S_D++
			// Check condition for 'D'
			if s_r+(S_D-S_U) == H+1 {
				Judge = true
			}
		}
	}

	// Initialize variables for string T
	T_L, T_R, T_U, T_D := 0, 0, 0, 0

	// Iterate through string T and adjust variables accordingly
	for x := 0; x < N; x++ {
		// Check current character in T
		switch T[x] {
		case 'L':
			// Adjust T_L variable
			if S_R-T_L+s_c != 1 {
				T_L++
			}
		case 'R':
			// Adjust T_R variable
			if s_c+(T_R-S_L) != W {
				T_R++
			}
		case 'U':
			// Adjust T_U variable
			if S_D-T_U+s_r != 1 {
				T_U++
			}
		case 'D':
			// Adjust T_D variable
			if s_r+(T_D-S_U) != H {
				T_D++
			}
		}
	}

	// Check final condition
	if Judge {
		fmt.Println("NO")
	} else {
		fmt.Println("YES")
	}
}

// <END-OF-CODE>
