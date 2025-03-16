
package main

import "fmt"

func main() {
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		var n int
		fmt.Scan(&n)
		fmt.Println(maxLeft(n))
	}
}

func maxLeft(n int) int {
	if n > 2 {
		return n - 2
	}
	return 0
}

