package main

import (
	"fmt"
)

func main() {
	var i, n int
	var tmp int
	var min, max, sum int = 1000000, -1000000, 0

	fmt.Print("Enter the number of integers: ")
	fmt.Scan(&n)

	for i = 0; i < n; i++ {
		fmt.Scan(&tmp)
		if min > tmp {
			min = tmp
		}
		if max < tmp {
			max = tmp
		}
		sum += tmp
	}

	fmt.Printf("%d %d %d\n", min, max, sum)
}

