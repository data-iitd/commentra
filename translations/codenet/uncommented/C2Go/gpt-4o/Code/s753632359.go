package main

import (
	"fmt"
)

func main() {
	var N, D int // N, D are integers between 1 and 20
	var ans, rem int

	fmt.Scan(&N, &D)

	ans = N / (D*2 + 1)
	rem = N % (D*2 + 1)

	if rem != 0 {
		ans = ans + 1
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
