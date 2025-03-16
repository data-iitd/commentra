package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the size of the island:")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the number of islands:")
	count, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	printIsland(n, count)
}

func printIsland(n, count int) {
	a := (n + 1) / 2
	b := n / 2
	max := a * a + b * b
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

