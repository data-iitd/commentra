package main

import (
	"fmt"
)

const INF = 100000

func main() {
	var D int
	var G int64
	fmt.Scan(&D)
	fmt.Scan(&G)

	p := make([]int, D)
	c := make([]int, D)

	for i := 0; i < D; i++ {
		fmt.Scan(&p[i])
		fmt.Scan(&c[i])
	}

	min := INF

	for bit := 0; bit < (1 << D); bit++ {
		score := int64(0)
		solveNum := 0

		for i := 0; i < D; i++ {
			if (bit & (1 << i)) != 0 {
				score += int64(100*(i+1)*p[i]) + int64(c[i])
				solveNum += p[i]
			}
		}

		if score < G {
			for i := D - 1; i >= 0; i-- {
				if (bit & (1 << i)) == 0 {
					for j := 0; j < p[i]-1; j++ {
						score += int64(100 * (i + 1))
						solveNum++

						if score >= G {
							break
						}
					}
				}

				if score >= G {
					break
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
