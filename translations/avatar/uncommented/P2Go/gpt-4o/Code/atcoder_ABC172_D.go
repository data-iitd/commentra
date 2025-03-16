package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	ans := 0
	for i := 1; i <= N; i++ {
		ans += i * (N / i) * (N/i + 1) / 2
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
