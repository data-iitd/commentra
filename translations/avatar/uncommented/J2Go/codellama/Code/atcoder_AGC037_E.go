
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N, K int
	var S string
	var firstTime bool
	var step int
	var sDash string
	var c byte
	var i int

	fmt.Scan(&N, &K)
	fmt.Scan(&S)
	firstTime = true
	step = 1
	for K > 0 {
		T := strings.Reverse(S)
		revU := strings.Reverse(S + T)
		revU = strings.Reverse(revU)
		sDash = S
		for i = N; i >= 0; i -= step {
			tmp := revU[i:i+N]
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
				c = sDash[0]
				for i = 0; i < N; i++ {
					fmt.Printf("%c", c)
				}
				fmt.Println()
				os.Exit(0)
			}
		} else {
			step += step
		}
		K--
		S = sDash
		S = strings.Reverse(S)
	}
	fmt.Println(strings.Reverse(S))
}

