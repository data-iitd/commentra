
package main

import "fmt"

func main() {
	var x, y int
	fmt.Scan(&x, &y)
	fmt.Println(max(x+y-3+(y-x)%3 > 0, 0))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

