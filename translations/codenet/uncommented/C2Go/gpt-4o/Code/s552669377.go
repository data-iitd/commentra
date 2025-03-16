package main

import (
	"fmt"
)

func main() {
	var n, tmp int
	min := int64(1000000)
	max := int64(-1000000)
	sum := int64(0)

	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		fmt.Scan(&tmp)
		if min > int64(tmp) {
			min = int64(tmp)
		}
		if max < int64(tmp) {
			max = int64(tmp)
		}
		sum += int64(tmp)
	}

	fmt.Printf("%d %d %d\n", min, max, sum)
}

// <END-OF-CODE>
