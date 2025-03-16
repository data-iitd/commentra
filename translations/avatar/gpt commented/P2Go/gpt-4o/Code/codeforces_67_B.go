package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	M := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&M[i])
	}

	for j := 0; j < n; j++ {
		var p int
		found := false
		for p = 0; p < n; p++ {
			if M[p] == 0 {
				fmt.Print(p + 1, " ")
				found = true
				break
			}
		}

		if found {
			for l := 0; l < p+1-k; l++ {
				M[l]--
			}
			M[p]--
		}
	}
}

// <END-OF-CODE>
