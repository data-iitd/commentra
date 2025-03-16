
package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	S := make([]byte, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&S[i])
	}
	aaaa := false
	if K >= 15 {
		aaaa = true
	} else if math.Pow(2, float64(K)) >= float64(N) {
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
		for i := 0; i < N; i++ {
			if S[i] == S[0] {
				count++
			} else {
				break
			}
		}
		if count*int(math.Pow(2, float64(K-1))) >= N {
			fmt.Println(string(S[0]) + strconv.Itoa(N))
		} else {
			S = string(S[0]) + string(S[0]) + string(S[1:])
			fmt.Println(string(S[0:N]))
		}
	}
}

func get_last_dict(S []byte) []byte {
	U := string(S) + string(S[len(S)-1:])
	c := min(S)
	p := U.Index(c)
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
	return []byte(U[minindex : minindex+N])
}

func check_normal_dict(U string, pointer1, pointer2 int) bool {
	for i := 0; i < N; i++ {
		if U[pointer1+i] > U[pointer2+i] {
			return true
		} else if U[pointer1+i] < U[pointer2+i] {
			return false
		}
	}
	return false
}

func min(S []byte) byte {
	min := S[0]
	for i := 1; i < N; i++ {
		if S[i] < min {
			min = S[i]
		}
	}
	return min
}

