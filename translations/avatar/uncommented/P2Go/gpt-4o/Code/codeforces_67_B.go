package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	input := ""
	fmt.Scan(&input)
	M := make([]int, n)
	for i, val := range strings.Split(input, " ") {
		M[i], _ = strconv.Atoi(val)
	}

	m := 0
	for j := 0; j < n; j++ {
		var p int
		for p = 0; p < n; p++ {
			if M[p] == 0 {
				fmt.Print(p+1, " ")
				break
			}
		}
		for l := 0; l < p+1-k; l++ {
			M[l]--
		}
		M[p]--
	}
}

// <END-OF-CODE>
