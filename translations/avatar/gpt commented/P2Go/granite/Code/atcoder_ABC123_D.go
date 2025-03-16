
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read integers x, y, z, and k from input
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	parts := strings.Split(input, " ")
	x, _ := strconv.Atoi(parts[0])
	y, _ := strconv.Atoi(parts[1])
	z, _ := strconv.Atoi(parts[2])
	k, _ := strconv.Atoi(parts[3])

	// Read list a of size x from input
	input, _ = reader.ReadString('\n')
	input = strings.TrimSpace(input)
	parts = strings.Split(input, " ")
	a := make([]int, x)
	for i := 0; i < x; i++ {
		a[i], _ = strconv.Atoi(parts[i])
	}

	// Read list b of size y from input
	input, _ = reader.ReadString('\n')
	input = strings.TrimSpace(input)
	parts = strings.Split(input, " ")
	b := make([]int, y)
	for i := 0; i < y; i++ {
		b[i], _ = strconv.Atoi(parts[i])
	}

	// Read list c of size z from input
	input, _ = reader.ReadString('\n')
	input = strings.TrimSpace(input)
	parts = strings.Split(input, " ")
	c := make([]int, z)
	for i := 0; i < z; i++ {
		c[i], _ = strconv.Atoi(parts[i])
	}

	// Initialize an empty list to store the sums of elements from lists a and b
	ab := make([]int, 0)

	// Calculate all possible sums of elements from list a and list b
	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			ab = append(ab, a[i]+b[j])
		}
	}

	// Sort the list of sums in descending order
	for i := 0; i < len(ab); i++ {
		for j := 0; j < len(ab)-1-i; j++ {
			if ab[j] < ab[j+1] {
				ab[j], ab[j+1] = ab[j+1], ab[j]
			}
		}
	}

	// Initialize an empty list to store the sums of the top k elements from ab and elements from list c
	abc := make([]int, 0)

	// Calculate sums of the top k elements from ab with each element in c
	for i := 0; i < min(k, x*y); i++ {
		for j := 0; j < z; j++ {
			abc = append(abc, ab[i]+c[j])
		}
	}

	// Sort the resulting sums in descending order
	for i := 0; i < len(abc); i++ {
		for j := 0; j < len(abc)-1-i; j++ {
			if abc[j] < abc[j+1] {
				abc[j], abc[j+1] = abc[j+1], abc[j]
			}
		}
	}

	// Print the top k sums from the final list abc
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
