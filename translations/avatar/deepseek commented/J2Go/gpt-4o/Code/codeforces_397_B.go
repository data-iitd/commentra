package main

import (
	"fmt"
)

const MOD = 1e9 + 7

func main() {
	var t int
	fmt.Scan(&t) // Read the number of test cases

	for t > 0 {
		t--

		var n, a, b int64
		fmt.Scan(&n, &a, &b) // Read n, a, and b

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

		low, high := int64(1), x+1
		var ans int64 = 1

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

// <END-OF-CODE>
