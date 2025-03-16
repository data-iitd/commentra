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

	fmt.Fscan(reader, &H, &W, &N)
	fmt.Fscan(reader, &s_r, &s_c)
	fmt.Fscan(reader, &S)
	fmt.Fscan(reader, &T)

	Judge := false
	var S_L, S_R, S_U, S_D int
	var T_L, T_R, T_U, T_D int

	for x := 0; x < N; x++ {
		if S[x] == 'L' {
			S_L++
			if S_L-T_R-s_c == 0 {
				Judge = true
			}
		} else if S[x] == 'R' {
			S_R++
			if s_c+(S_R-T_L) == W+1 {
				Judge = true
			}
		} else if S[x] == 'U' {
			S_U++
			if S_U-T_D-s_r == 0 {
				Judge = true
			}
		} else if S[x] == 'D' {
			S_D++
			if s_r+(S_D-T_U) == H+1 {
				Judge = true
			}
		}

		if T[x] == 'L' {
			if S_R-T_L+s_c != 1 {
				T_L++
			}
		} else if T[x] == 'R' {
			if s_c+(T_R-S_L) != W {
				T_R++
			}
		} else if T[x] == 'U' {
			if S_D-T_U+s_r != 1 {
				T_U++
			}
		} else if T[x] == 'D' {
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
}
