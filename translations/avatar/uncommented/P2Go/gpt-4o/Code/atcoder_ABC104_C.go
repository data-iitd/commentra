package main

import (
	"fmt"
	"math"
)

func main() {
	var D, G int
	fmt.Scan(&D, &G)

	PC := make([][2]int, D)
	for i := 0; i < D; i++ {
		fmt.Scan(&PC[i][0], &PC[i][1])
	}

	ans := math.MaxInt32
	for i := 0; i < (1 << D); i++ {
		score := 0
		problem := 0
		for j := 0; j < D; j++ {
			if (i>>j)&1 == 1 {
				score += 100 * (j + 1) * PC[j][0] + PC[j][1]
				problem += PC[j][0]
			}
		}
		if score > G {
			continue
		}
		left := G - score
		for j := 0; j < D; j++ {
			if (i>>j)&1 == 1 {
				continue
			}
			if left > 100*(j+1)*PC[j][0]+PC[j][1] {
				continue
			} else {
				tmp := (left + (100 * (j + 1)) - 1) / (100 * (j + 1))
				ans = min(ans, problem+min(tmp, PC[j][0]))
			}
		}
	}
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
