package main

import (
	"fmt"
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
	} else if (1 << K) >= N {
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
		for count < N && S[count] == S[0] {
			count++
		}
		if count*(1<<(K-1)) >= N {
			fmt.Println(strings.Repeat(string(S[0]), N))
		} else {
			S = strings.Repeat(string(S[0]), count*(1<<(K-1)-1)) + S
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

	for p <= len(U)-1 {
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

func minChar(s string) rune {
	min := s[0]
	for _, char := range s {
		if char < min {
			min = char
		}
	}
	return min
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// <END-OF-CODE>
