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
	fmt.Println("Enter the size of the grid: ")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the number of 'L' characters: ")
	count, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	printIsland(n, count)
}

// Method to print the island pattern based on the given size and count of 'L' characters
func printIsland(n, count int) {
	a := (n + 1) / 2
	b := n / 2
	max := a * a + b * b

	// Checking if the requested count exceeds the maximum possible 'L' characters
	if count > max {
		fmt.Println("NO")
		return
	}

	fmt.Println("YES")

	// Building the island grid
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

