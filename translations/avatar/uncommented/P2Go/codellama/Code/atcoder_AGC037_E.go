
package main

import (
	"fmt"
	"strings"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	S := make([]byte, N)
	fmt.Scan(&S)
	aaaa := false
	if K >= 15 {
		aaaa = true
	} else if 1<<K >= N {
		aaaa = true
	}
	if aaaa {
		fmt.Println(min(S) * N)
		return
	}
	S = get_last_dict(S)
	if K == 1 {
		fmt.Println(string(S))
	} else {
		count := 0
		for _, c := range S {
			if c == S[0] {
				count++
			} else {
				break
			}
		}
		if count*(1<<(K-1)) >= N {
			fmt.Println(string(S[0]) + strings.Repeat(string(S[0]), N-1))
		} else {
			S = string(S[0]) + strings.Repeat(string(S[0]), count*(1<<(K-1))-1) + string(S)
			fmt.Println(S[:N])
		}
	}
}

func get_last_dict(s_str string) string {
	U := s_str + s_str[:len(s_str)-1]
	c := min(s_str)
	p := strings.Index(U, string(c))
	minindex := p
	p++
	for p <= N {
		if U[p] == c {
			if check_normal_dict(U, minindex, p) {
				minindex = p
			}
		}
		p++
	}
	return U[minindex : minindex+N]
}

func check_normal_dict(u string, pointer1, pointer2 int) bool {
	for i := 0; i < N; i++ {
		if u[pointer1+i] > u[pointer2+i] {
			return true
		} else if u[pointer1+i] < u[pointer2+i] {
			return false
		}
	}
	return false
}

func min(s string) byte {
	min := s[0]
	for _, c := range s {
		if c < min {
			min = c
		}
	}
	return min
}

// 