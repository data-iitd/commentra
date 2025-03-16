
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
	fmt.Println("Enter the dimensions of the grid (n: number of rows, m: number of columns)")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	n, _ := strconv.Atoi(strings.Split(input, " ")[0])
	m, _ := strconv.Atoi(strings.Split(input, " ")[1])
	fmt.Println("Enter the grid")
	grid := make([]string, n)
	for i := 0; i < n; i++ {
		grid[i], _ = reader.ReadString('\n')
	}
	fmt.Println("The number of unique non-negative differences is", uniqueNonNegativeDifferences(grid))
}

func uniqueNonNegativeDifferences(grid []string) int {
	c := make(map[int]bool)
	for _, s := range grid {
		c[strings.Index(s, "S") - strings.Index(s, "G")] = true
	}
	if any(func(a int) bool { return a < 0 }, c) {
		return -1
	}
	return len(c)
}

func any(f func(int) bool, s []int) bool {
	for _, v := range s {
		if f(v) {
			return true
		}
	}
	return false
}

