

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

	var n, m int
	fmt.Fscanf(reader, "%d %d\n", &n, &m)
	// Read the dimensions of the grid (n: number of rows, m: number of columns)

	c := make(map[int]bool)
	for i := 0; i < n; i++ {
		s, _ := reader.ReadString('\n')
		s = strings.TrimSpace(s)
		s = strings.ReplaceAll(s, "\n", "")
		// Read the string and remove any leading or trailing whitespace

		sI := strings.Index(s, "S")
		gI := strings.Index(s, "G")
		// Find the index of 'S' and 'G' in the string

		diff := gI - sI
		// Calculate the difference between the indices of 'S' and 'G'

		c[diff] = true
		// Store the difference in the map 'c'
	}

	count := 0
	for _, v := range c {
		if v {
			count++
		}
		// Count the number of unique non-negative differences in the map 'c'
	}

	if count == 0 {
		fmt.Println(-1)
		// If there is no unique non-negative difference, print '-1'
	} else {
		fmt.Println(count)
		// Otherwise, print the number of unique non-negative differences
	}
}
