
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input: four integers x, y, z, and k followed by x * y integers each for lists a, b, and c
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	parts := strings.Split(input, " ")
	x, _ := strconv.Atoi(parts[0])
	y, _ := strconv.Atoi(parts[1])
	z, _ := strconv.Atoi(parts[2])
	k, _ := strconv.Atoi(parts[3])
	a := make([]int, x*y)
	b := make([]int, x*y)
	c := make([]int, z)
	for i := 0; i < x*y; i++ {
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		a[i], _ = strconv.Atoi(input)
	}
	for i := 0; i < x*y; i++ {
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		b[i], _ = strconv.Atoi(input)
	}
	for i := 0; i < z; i++ {
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		c[i], _ = strconv.Atoi(input)
	}

	// Initialize an empty list ab to store the sum of each element from list a with each element from list b
	ab := make([]int, 0)

	// Iterate through each element in list a for i, and for each element in list b for j, append their sum to list ab
	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			ab = append(ab, a[i]+b[j])
		}
	}

	// Sort list ab in descending order
	for i := 0; i < len(ab); i++ {
		for j := 0; j < len(ab)-1-i; j++ {
			if ab[j] < ab[j+1] {
				ab[j], ab[j+1] = ab[j+1], ab[j]
			}
		}
	}

	// Initialize an empty list abc to store the sum of each element from list ab with each element from list c
	abc := make([]int, 0)

	// Iterate through each valid index i in the range of min(k, x * y), and for each index j in the range of z, append their sum to list abc
	for i := 0; i < min(k, x*y); i++ {
		for j := 0; j < z; j++ {
			abc = append(abc, ab[i]+c[j])
		}
	}

	// Sort list abc in descending order
	for i := 0; i < len(abc); i++ {
		for j := 0; j < len(abc)-1-i; j++ {
			if abc[j] < abc[j+1] {
				abc[j], abc[j+1] = abc[j+1], abc[j]
			}
		}
	}

	// Iterate through the first k elements of list abc and print each element
	for i := 0; i < k; i++ {
		fmt.Println(abc[i])
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

