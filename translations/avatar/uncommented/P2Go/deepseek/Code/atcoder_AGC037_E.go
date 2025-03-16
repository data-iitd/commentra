package main

import (
	"fmt"
	"math"
	"strings"
)

func getLastDict(s string) string {
	n := len(s)
	U := s + s[0:n-1]
	c := minChar(s)
	p := strings.Index(U, c)
	minIndex := p
	p++
	for p < n {
		if U[p] == c {
			if checkNormalDict(U, minIndex, p, n) {
				minIndex = p
			}
		}
		p++
	}
	return U[minIndex : minIndex+n]
}

func checkNormalDict(u string, pointer1, pointer2, n int) bool {
	for i := 0; i < n; i++ {
		if u[pointer1+i] > u[pointer2+i] {
			return true
		} else if u[pointer1+i] < u[pointer2+i] {
			return false
		}
	}
	return false
}

func minChar(s string) string {
	minChar := s[0]
	for _, char := range s {
		if char < minChar {
			minChar = char
		}
	}
	return string(minChar)
}

func main() {
	var N, K int
	var S string
	fmt.Scan(&N, &K)
	fmt.Scan(&S)

	aaaa := false
	if K >= 15 {
		aaaa = true
	} else if int(math.Pow(2, float64(K))) >= N {
		aaaa = true
	}
	if aaaa {
		minChar := minChar(S)
		fmt.Println(string(minChar) * N)
		return
	}

	S = getLastDict(S)
	if K == 1 {
		fmt.Println(S)
	} else {
		count := 0
		for i := 0; i < len(S); i++ {
			if S[i] == S[0] {
				count++
			} else {
				break
			}
		}
		if count*(int(math.Pow(2, float64(K-1)))) >= N {
			fmt.Println(strings.Repeat(string(S[0]), N))
		} else {
			S = strings.Repeat(string(S[0]), (count*(int(math.Pow(2, float64(K-1)))-1))) + S
			fmt.Println(S[:N])
		}
	}
}
