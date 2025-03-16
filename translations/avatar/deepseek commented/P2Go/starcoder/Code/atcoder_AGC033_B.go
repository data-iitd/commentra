package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	H, W, N := readThreeNums(reader)
	s_r, s_c := readTwoNums(reader)
	S := readNNums(reader, N)
	T := readNNums(reader, N)

	Judge := false
	S_L, S_R, S_U, S_D := 0, 0, 0, 0
	T_L, T_R, T_U, T_D := 0, 0, 0, 0

	for x := 0; x < N; x++ {
		if S[x] == 'L' {
			S_L += 1
			if S_L-T_R-s_c == 0 {
				Judge = true
			}
		} else if S[x] == 'R' {
			S_R += 1
			if s_c+(S_R-T_L) == W+1 {
				Judge = true
			}
		} else if S[x] == 'U' {
			S_U += 1
			if S_U-T_D-s_r == 0 {
				Judge = true
			}
		} else if S[x] == 'D' {
			S_D += 1
			if s_r+(S_D-T_U) == H+1 {
				Judge = true
			}
		}

		if T[x] == 'L' {
			if S_R-T_L+s_c!= 1 {
				T_L += 1
			}
		}
		if T[x] == 'R' {
			if s_c+(T_R-S_L)!= W {
				T_R += 1
			}
		}
		if T[x] == 'U' {
			if S_D-T_U+s_r!= 1 {
				T_U += 1
			}
		}
		if T[x] == 'D' {
			if s_r+(T_D-S_U)!= H {
				T_D += 1
			}
		}
	}

	if Judge {
		fmt.Println("NO")
	} else {
		fmt.Println("YES")
	}
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
	res := readNNums(reader, 3)
	a, b, c = res[0], res[1], res[2]
	return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

