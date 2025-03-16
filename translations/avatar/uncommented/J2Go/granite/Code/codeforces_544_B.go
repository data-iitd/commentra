
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := reader.ReadString('\n')
	count, _ := reader.ReadString('\n')
	printIsland(n, count)
}

func printIsland(n, count string) {
	a := (len(n) + 1) / 2
	b := len(n) / 2
	max := a*a + b*b
	if len(count) > max {
		fmt.Println("NO")
		return
	}
	fmt.Println("YES")
	for i := 0; i < len(n); i++ {
		sb := ""
		for j := 0; j < len(n); j++ {
			if (i+j)%2 == 0 && len(count) > 0 {
				sb += "L"
				count = count[1:]
			} else {
				sb += "S"
			}
		}
		fmt.Println(sb)
	}
}

