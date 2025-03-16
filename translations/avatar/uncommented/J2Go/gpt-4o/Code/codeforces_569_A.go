package main

import (
	"fmt"
)

func main() {
	var T, S, q int
	fmt.Scan(&T, &S, &q)

	previous := int64(S)
	answer := 0

	for previous < int64(T) {
		answer++
		previous *= int64(q)
	}

	fmt.Println(answer)
}

// <END-OF-CODE>
