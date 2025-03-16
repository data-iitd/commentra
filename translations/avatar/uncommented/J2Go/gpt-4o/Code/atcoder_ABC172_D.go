package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	var ans int64 = 0

	for i := 1; i <= n; i++ {
		ans += int64(i) * (int64(n) / int64(i)) * ((int64(n) / int64(i)) + 1) / 2
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
