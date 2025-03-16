
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

	// Read input
	n, m := readTwoInts(reader)

	// Initialize an empty set
	c := make(map[int]bool)

	// Populate set c with differences between indices of 'S' and 'G' in each string
	for i := 0; i < n; i++ {
		s, _ := reader.ReadString('\n')
		s = strings.TrimSpace(s)

		// Find the indices of 'S' and 'G' in the current string
		indexS := strings.Index(s, "S")
		indexG := strings.Index(s, "G")

		// Calculate the difference and add it to the set
		difference := indexS - indexG
		c[difference] = true
	}

	// Check if there is any negative number in set c and print accordingly
	count := 0
	for key := range c {
		if key < 0 {
			fmt.Println(-1)
			return
		}
		count++
	}
	fmt.Println(count)
}

func readTwoInts(reader *bufio.Reader) (int, int) {
	res := make([]int, 2)
	str, _ := reader.ReadString('\n')
	arr := strings.Split(str, " ")

	for i := 0; i < 2; i++ {
		res[i], _ = strconv.Atoi(arr[i])
	}

	return res[0], res[1]
}

