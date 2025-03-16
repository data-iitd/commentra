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
		T := []rune(S)
		for i := 0; i < N; i++ {
			T[i], T[N-1-i] = T[N-1-i], T[i]
		}
		revU := S + string(T)
		revU = reverse(revU)
		sDash := S

		for i := N; i >= 0; i -= step {
			tmp := revU[i : i+N]
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
		S = reverse(S)
	}
	fmt.Println(reverse(S))
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

