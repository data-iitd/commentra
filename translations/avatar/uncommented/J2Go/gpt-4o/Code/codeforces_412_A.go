package main

import (
	"fmt"
)

func main() {
	var n, k int
	var a string
	fmt.Scan(&n, &k)
	fmt.Scan(&a)

	if k > n/2 {
		for k < n {
			fmt.Println("RIGHT")
			k++
		}
	} else {
		for k > 1 {
			fmt.Println("LEFT")
			k--
		}
	}

	if k == 1 {
		for i := 0; i < len(a); i++ {
			fmt.Println("PRINT", string(a[i]))
			if (i + 1) < len(a) {
				fmt.Println("RIGHT")
			}
		}
	} else {
		for i := len(a) - 1; i >= 0; i-- {
			fmt.Println("PRINT", string(a[i]))
			if (i - 1) >= 0 {
				fmt.Println("LEFT")
			}
		}
	}
}

// <END-OF-CODE>
