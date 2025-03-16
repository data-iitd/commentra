package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	// n gu m ki
	ans := 0
	// gu gu
	ans += n * (n - 1) / 2

	// kiki
	ans += m * (m - 1) / 2

	fmt.Println(ans)
}

// <END-OF-CODE>
