package main

import (
	"fmt"
	"math"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	x := 0
	if k <= int(math.Max(float64(n*n/2), float64(n*n-(n*n/2)))) {
		fmt.Println("YES")
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if i%2 == j%2 && x < k {
					fmt.Print("L")
					x++
				} else {
					fmt.Print("S")
				}
			}
			fmt.Println()
		}
	} else {
		fmt.Println("NO")
	}
}

