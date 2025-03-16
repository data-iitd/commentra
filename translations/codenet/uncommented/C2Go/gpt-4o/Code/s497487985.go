package main

import (
	"fmt"
)

func main() {
	var n int64
	var k, q int64
	var a [100001]int64
	var point [100001]int64

	fmt.Scan(&n, &k, &q)

	// Read the input and update points
	for i := int64(0); i < q; i++ {
		fmt.Scan(&a[i])
		point[a[i]-1]++
	}

	// Determine if each player has enough points
	for i := int64(0); i < n; i++ {
		if k-(q-point[i]) > 0 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

// <END-OF-CODE>
