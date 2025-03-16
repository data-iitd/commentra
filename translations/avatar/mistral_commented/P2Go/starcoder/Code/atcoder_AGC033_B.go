#######
# Code
#######

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read H, W, N
	line, _ := reader.ReadString('\n')
	H, W, N := strings.Split(line, " "), 0, 0
	for i := 0; i < len(H); i++ {
		H[i], _ = strconv.Atoi(H[i])
	}
	H, W, N = H[0], H[1], H[2]
	// Read S_r, S_c
	line, _ = reader.ReadString('\n')
	S_r, S_c := strings.Split(line, " "), 0, 0
	for i := 0; i < len(S_r); i++ {
		S_r[i], _ = strconv.Atoi(S_r[i])
	}
	S_r, S_c = S_r[0], S_r[1]
	// Read S
	line, _ = reader.ReadString('\n')
	S := strings.Split(line, " ")
	// Read T_r, T_c
	line, _ = reader.ReadString('\n')
	T_r, T_c := strings.Split(line, " "), 0, 0
	for i := 0; i < len(T_r); i++ {
		T_r[i], _ = strconv.Atoi(T_r[i])
	}
	T_r, T_c = T_r[0], T_r[1]
	// Read T
	line, _ = reader.ReadString('\n')
	T := strings.Split(line, " ")
	// Initialize variables
	Judge := false
	// Initialize variables for string S
	S_L, S_R, S_U, S_D := 0, 0, 0, 0
	// Iterate through string S
	for x := 0; x < N; x++ {
		// Check current character in S
		if S[x] == "L" {
			S_L += 1
			// Check condition for 'L'
			if S_L - T_r - S_c == 0 {
				Judge = true
			}
		} else if S[x] == "R" {
			S_R += 1
			// Check condition for 'R'
			if S_c + (S_R - T_r) == W {
				Judge = true
			}
		} else if S[x] == "U" {
			S_U += 1
			// Check condition for 'U'
			if S_U - T_r - S_r == 0 {
				Judge = true
			}
		} else if S[x] == "D" {
			S_D += 1
			// Check condition for 'D'
			if S_r + (S_D - T_r) == H {
				Judge = true
			}
		}
	}
	// Initialize variables for string T
	if T_L == 0 {
		T_L = 0
	}
	if T_R == 0 {
		T_R = 0
	}
	if T_U == 0 {
		T_U = 0
	}
	if T_D == 0 {
		T_D = 0
	}
	// Iterate through string T and adjust variables accordingly
	for x := 0; x < N; x++ {
		// Check current character in T
		if T[x] == "L" {
			// Adjust T_L variable
			if S_R - T_L + S_c!= 1 {
				T_L += 1
			}
		}
		if T[x] == "R" {
			// Adjust T_R variable
			if S_c + (T_R - S_L)!= W {
				T_R += 1
			}
		}
		if T[x] == "U" {
			// Adjust T_U variable
			if S_D - T_U + S_r!= 1 {
				T_U += 1
			}
		}
		if T[x] == "D" {
			// Adjust T_D variable
			if S_r + (T_D - S_U)!= H {
				T_D += 1
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

