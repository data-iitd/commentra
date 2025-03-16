package main

import (
	"fmt"
)

func main() {
	const INF = 100000
	var D, G int
	fmt.Scan(&D, &G)

	p := make([]int, D)
	c := make([]int, D)
	for i := 0; i < D; i++ {
		fmt.Scan(&p[i], &c[i])
	}

	min := INF
	for bit := 0; bit < (1 << D); bit++ {
		score := 0
		solveNum := 0
		for i := 0; i < D; i++ {
			if (bit & (1 << i)) != 0 {
				score += 100*(i+1)*p[i] + c[i]
				solveNum += p[i]
			}
		}
		if score < G {
			loop:
			for i := D - 1; i >= 0; i-- {
				if (bit & (1 << i)) == 0 {
					for j := 0; j < p[i]-1; j++ {
						score += 100 * (i + 1)
						solveNum++
						if score >= G {
							break loop
						}
					}
				}
			}
		}
		if score >= G {
			if solveNum < min {
				min = solveNum
			}
		}
	}
	fmt.Println(min)
}

