```go
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var H, W, N int
	var s_r, s_c int
	var S, T string
	var Judge bool

	// Initialize variables
	fmt.Fscan(reader, &H, &W, &N)
	fmt.Fscan(reader, &s_r, &s_c)
	fmt.Fscan(reader, &S)
	fmt.Fscan(reader, &T)

	// Initialize variables for string S
	var S_L, S_R, S_U, S_D int

	// Iterate through string S
	for x := 0; x < N; x++ {
		// Check current character in S
		if S[x] == 'L' {
			S_L++
			// Check condition for 'L'
			if S_L - S_R - s_c == 0 {
				Judge = true
			}
		} else if S[x] == 'R' {
			S_R++
			// Check condition for 'R'
			if s_c + (S_R - S_L) == W + 1 {
				Judge = true
			}
		} else if S[x] == 'U' {
			S_U++
			// Check condition for 'U'
			if S_U - S_D - s_r == 0 {
				Judge = true
			}
		} else if S[x] == 'D' {
			S_D++
			// Check condition for 'D'
			if s_r + (S_D - S_U) == H + 1 {
				Judge = true
			}
		}
	}

	// Initialize variables for string T
	var T_L, T_R, T_U, T_D int

	// Iterate through string T and adjust variables accordingly
	for x := 0; x < N; x++ {
		// Check current character in T
		if T[x] == 'L' {
			// Adjust T_L variable
			if S_R - T_L + s_c != 1 {
				T_L++
			}
		} else if T[x] == 'R' {
			// Adjust T_R variable
			if s_c + (T_R - T_L) != W {
				T_R++
			}
		} else if T[x] == 'U' {
			// Adjust T_U variable
			if S_D - T_U + s_r != 1 {
				T_U++
			}
		} else if T[x] == 'D' {
			// Adjust T_D variable
			if s_r + (T_D - T_U) != H {
				T_D++
			}
		}
	}

	// Check final condition
	if Judge {
		fmt.Fprintln(writer, "NO")
	} else {
		fmt.Fprintln(writer, "YES")
	}
}
