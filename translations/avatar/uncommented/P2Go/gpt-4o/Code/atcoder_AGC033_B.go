package main

import (
	"fmt"
)

func main() {
	var H, W, N int
	fmt.Scan(&H, &W, &N)
	var s_r, s_c int
	fmt.Scan(&s_r, &s_c)
	var S, T string
	fmt.Scan(&S)
	fmt.Scan(&T)

	Judge := false
	S_L, S_R, S_U, S_D := 0, 0, 0, 0
	T_L, T_R, T_U, T_D := 0, 0, 0, 0

	for x := 0; x < N; x++ {
		switch S[x] {
		case 'L':
			S_L++
			if S_L-T_R-s_c == 0 {
				Judge = true
			}
		case 'R':
			S_R++
			if s_c+(S_R-T_L) == W+1 {
				Judge = true
			}
		case 'U':
			S_U++
			if S_U-T_D-s_r == 0 {
				Judge = true
			}
		case 'D':
			S_D++
			if s_r+(S_D-T_U) == H+1 {
				Judge = true
			}
		}

		switch T[x] {
		case 'L':
			if S_R-T_L+s_c != 1 {
				T_L++
			}
		case 'R':
			if s_c+(T_R-S_L) != W {
				T_R++
			}
		case 'U':
			if S_D-T_U+s_r != 1 {
				T_U++
			}
		case 'D':
			if s_r+(T_D-S_U) != H {
				T_D++
			}
		}
	}

	if Judge {
		fmt.Println("NO")
	} else {
		fmt.Println("YES")
	}
}

// <END-OF-CODE>
