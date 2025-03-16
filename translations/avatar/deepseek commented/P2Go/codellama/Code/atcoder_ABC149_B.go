
package main

import "fmt"

func main() {
	var cookies []int
	fmt.Scan(&cookies)
	leftOver := cookies[0] - cookies[2]
	takahashi := max(0, leftOver)
	fmt.Println(takahashi, cookies[1]-takahashi)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

