
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, count int
	fmt.Scan(&n, &count)
	printIsland(n, count)
}

func printIsland(n, count int) {
	a := (n + 1) / 2
	b := n / 2
	max := a*a + b*b
	if count > max {
		fmt.Println("NO")
		return
	}
	fmt.Println("YES")
	for i := 0; i < n; i++ {
		var sb strings.Builder
		for j := 0; j < n; j++ {
			if (i+j)%2 == 0 && count > 0 {
				sb.WriteString("L")
				count--
			} else {
				sb.WriteString("S")
			}
		}
		fmt.Println(sb.String())
	}
}

