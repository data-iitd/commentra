package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	var S string
	fmt.Scan(&S)

	aaaa := false
	if K >= 15 {
		aaaa = true
	} else if int(math.Pow(2, float64(K))) >= N {
		aaaa = true
	}

	if aaaa {
		fmt.Println(strings.Repeat(string(minChar(S)), N))
		return
	}

	S = getLastDict(S, N)
	if K == 1 {
		fmt.Println(S)
	} else {
		count := 0
		for i := 0; i < N; i++ {
			if S[i] == S[0] {
				count++
			} else {
				break
			}
		}
		if count*(int(math.Pow(2, float64(K-1)))) >= N {
			fmt.Println(strings.Repeat(string(S[0]), N))
		} else {
			S = strings.Repeat(string(S[0]), count*(int(math.Pow(2, float64(K-1)))-1)) + S
			fmt.Println(S[:N])
		}
	}
}

func getLastDict(sStr string, N int) string {
	U := sStr + reverse(sStr)
	c := minChar(sStr)
	p := strings.Index(U, string(c))
	minIndex := p
	p++

	for p <= len(U) {
		if U[p] == c {
			if checkNormalDict(U, minIndex, p, N) {
				minIndex = p
			}
		}
		p++
	}
	return U[minIndex : minIndex+N]
}

func checkNormalDict(u string, pointer1, pointer2, N int) bool {
	for i := 0; i < N; i++ {
		if u[pointer1+i] > u[pointer2+i] {
			return true
		} else if u[pointer1+i] < u[pointer2+i] {
			return false
		}
	}
	return false
}

func minChar(s string) byte {
	min := s[0]
	for i := 1; i < len(s); i++ {
		if s[i] < min {
			min = s[i]
		}
	}
	return min
}

func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

// <END-OF-CODE>
