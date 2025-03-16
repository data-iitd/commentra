package main

import (
	"fmt"
)

func main() {
	var h, a int
	fmt.Scan(&h, &a)

	sho := h / a
	am := h % a

	if am != 0 {
		sho += 1
	}

	fmt.Println(sho)
}

// <END-OF-CODE>
