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

	firstTime := true
	step := 1

	for K > 0 {
		T := reverse(S)
		revU := reverse(S + T)

		sDash := S
		for i := N; i >= 0; i -= step {
			tmp := revU[i : i+N]
			if sDash > tmp {
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
				c := string(sDash[0])
				for i := 0; i < N; i++ {
					fmt.Print(c)
				}
				fmt.Println()
				return
			}
		} else {
			step += step
		}
		K--
		S = reverse(sDash)
	}

	fmt.Println(reverse(S))
}

func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}
