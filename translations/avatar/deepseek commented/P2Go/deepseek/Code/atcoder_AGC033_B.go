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

	var H, W, N, s_r, s_c int
	var S, T string
	fmt.Fscan(reader, &H, &W, &N, &s_r, &s_c)
	fmt.Fscan(reader, &S)
	fmt.Fscan(reader, &T)

	Judge := false
	var S_L, S_R, S_U, S_D int
	var T_L, T_R, T_U, T_D int

	for i := 0; i < N; i++ {
		switch S[i] {
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

		switch T[i] {
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
		fmt.Fprintln(writer, "NO")
	} else {
		fmt.Fprintln(writer, "YES")
	}
