
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	var n, k int
	fmt.Sscanf(os.Args[1], "%d", &n)
	fmt.Sscanf(os.Args[2], "%d", &k)
	if k <= int(math.Max(float64(n*n/2), float64(n*n-n*n/2))) {
		fmt.Println("YES")
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if i%2 == j%2 && k > 0 {
					fmt.Print("L")
					k--
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

