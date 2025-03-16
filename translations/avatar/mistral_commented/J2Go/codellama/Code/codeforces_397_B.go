
package main

import (
	"fmt"
	"math"
)

func main() {
	var t int
	fmt.Scan(&t)
	for t > 0 {
		t--
		var n, a, b int
		fmt.Scan(&n, &a, &b)
		if n < a {
			fmt.Println("No")
			continue
		}
		if a == b {
			if n%a == 0 {
				fmt.Println("Yes")
			} else {
				fmt.Println("No")
			}
			continue
		}
		x := b / (b - a)
		if n > x*a {
			fmt.Println("Yes")
			continue
		}
		low := 1
		high := x + 1
		ans := 1
		for low <= high {
			mid := (low + high) / 2
			if mid*a < n {
				low = mid + 1
			} else {
				ans = mid
				high = mid - 1
			}
		}
		if n > (ans-1)*b && n < ans*a {
			fmt.Println("No")
		} else {
			fmt.Println("Yes")
		}
	}
}

