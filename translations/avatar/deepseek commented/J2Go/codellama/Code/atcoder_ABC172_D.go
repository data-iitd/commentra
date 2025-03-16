
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	ans := 0
	for i := 1; i < n+1; i++ {
		term := n / i
		sum := term * (term + 1) / 2
		ans += i * sum
	}
	fmt.Println(ans)
}

