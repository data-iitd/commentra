package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	var N, K int
	var S string
	fmt.Scan(&N, &K)
	fmt.Scan(&S)

	firstTime := true
	step := 1

	for K > 0 {
		T := S
		T = reverseString(T)
		revU := S + T
		revU = reverseString(revU)
		sDash := S

		for i := N; i >= 0; i -= step {
			tmp := revU[i-N : i]
			if strings.Compare(sDash, tmp) > 0 {
				sDash = tmp
			} else {
				if !firstTime {
					break
				}
			}
		}

		if firstTime {
			firstTime = false
			if math.Pow(2, float64(K)) > float64(N) {
				c := sDash[0]
				for i := 0; i < N; i++ {
					fmt.Print(string(c))
				}
				fmt.Println()
				return
			}
		} else {
			step += step
		}
		K--
		S = sDash
		S = reverseString(S)
	}
	fmt.Println(reverseString(S))
}

func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

