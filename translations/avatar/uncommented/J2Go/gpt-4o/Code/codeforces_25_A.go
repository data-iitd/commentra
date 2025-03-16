package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	array := make([]int, n+1)

	for i := 1; i <= n; i++ {
		fmt.Scan(&array[i])
	}

	odd, even := 0, 0
	oddInd, evenInd := 0, 0

	for i := 1; i <= n; i++ {
		if array[i]%2 == 0 {
			even++
			evenInd = i
		} else {
			odd++
			oddInd = i
		}
	}

	if odd > even {
		fmt.Println(evenInd)
	} else {
		fmt.Println(oddInd)
	}
}

// <END-OF-CODE>
