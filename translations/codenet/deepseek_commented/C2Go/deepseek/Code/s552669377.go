package main

import (
	"fmt"
)

func main() {
	var i, n int
	var tmp int
	var min, max, sum int64 = 1000000, -1000000, 0

	fmt.Scan(&n)

	for i = 0; i < n; i++ {
		fmt.Scan(&tmp)
		if min > tmp {
			min = int64(tmp)
		}
		if max < tmp {
			max = int64(tmp)
		}
		sum += int64(tmp)
	}

	fmt.Printf("%d %d %d\n", min, max, sum)
}

