package main

import "fmt"

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	M := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&M[i])
	}
	m := 0
	for j := 0; j < n; j++ {
		for p := 0; p < n; p++ {
			if M[p] == 0 {
				fmt.Print(p+1, " ")
				break
			}
		}
		for l := p + 1 - k; l < p; l++ {
			M[l]--
		}
		M[p]--
	}
}

