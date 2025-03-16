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
		minChar := S[0]
		for _, char := range S {
			if char < minChar {
				minChar = char
			}
		}
		result := strings.Repeat(string(minChar), N)
		fmt.Println(result)
		return
	}

	getLastDict := func(s string) string {
		U := s + s[len(s)-1:0:-1]
		c := s[0]
		for _, char := range s {
			if char < c {
				c = char
			}
		}
		p := strings.Index(U, string(c))
		minindex := p
		p++
		for p < len(U)-len(s)+1 {
			if U[p] == c {
				if checkNormalDict(U, minindex, p) {
					minindex = p
				}
			}
			p++
		}
		return U[minindex : minindex+len(s)]
	}

	checkNormalDict := func(u string, pointer1, pointer2 int) bool {
		for i := 0; i < len(u)-pointer1; i++ {
			if u[pointer1+i] > u[pointer2+i] {
				return true
			} else if u[pointer1+i] < u[pointer2+i] {
				return false
			}
		}
		return false
	}

	S = getLastDict(S)

	if K == 1 {
		fmt.Println(S)
	} else {
		count := 0
		for _, char := range S {
			if char == rune(S[0]) {
				count++
			} else {
				break
			}
		}

		if count*int(math.Pow(2, float64(K-1))) >= N {
			fmt.Println(strings.Repeat(string(S[0]), N))
		} else {
			S = strings.Repeat(string(S[0]), count*(int(math.Pow(2, float64(K-1)))-1)) + S
			fmt.Println(S[:N])
		}
	}
}
