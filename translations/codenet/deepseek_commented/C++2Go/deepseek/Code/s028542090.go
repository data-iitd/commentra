package main

import (
	"fmt"
)

func main() {
	var k int
	var a [100100]int
	fmt.Scan(&k)

	for i := 0; i < k; i++ {
		fmt.Scan(&a[i])
	}

	min, max := 2, 3

	if a[k-1] != 2 {
		fmt.Println(-1)
		return
	}

	for i := k - 2; i >= 0; i-- {
		if a[i] > max {
			fmt.Println(-1)
			return
		} else {
			max = ((max / a[i]) + 1) * a[i] - 1
			if min%a[i] != 0 {
				min = ((min / a[i]) + 1) * a[i]
			}
		}

		if max <= min {
			fmt.Println(-1)
			return
		}
	}

	fmt.Printf("%d %d\n", min, max)
}

