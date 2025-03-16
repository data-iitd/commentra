package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	// Read integers x, y, z, and k from input
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	x, _ := strconv.Atoi(parts[0])
	y, _ := strconv.Atoi(parts[1])
	z, _ := strconv.Atoi(parts[2])
	k, _ := strconv.Atoi(parts[3])

	// Read list a of size x from input
	scanner.Scan()
	a := []int{}
	for _, part := range strings.Split(scanner.Text(), " ") {
		num, _ := strconv.Atoi(part)
		a = append(a, num)
	}

	// Read list b of size y from input
	scanner.Scan()
	b := []int{}
	for _, part := range strings.Split(scanner.Text(), " ") {
		num, _ := strconv.Atoi(part)
		b = append(b, num)
	}

	// Read list c of size z from input
	scanner.Scan()
	c := []int{}
	for _, part := range strings.Split(scanner.Text(), " ") {
		num, _ := strconv.Atoi(part)
		c = append(c, num)
	}

	// Initialize an empty list to store the sums of elements from lists a and b
	ab := []int{}

	// Calculate all possible sums of elements from list a and list b
	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			ab = append(ab, a[i]+b[j])
		}
	}

	// Sort the list of sums in descending order
	sort.Slice(ab, func(i, j int) bool {
		return ab[i] > ab[j]
	})

	// Initialize an empty list to store the sums of the top k elements from ab and elements from list c
	abc := []int{}

	// Calculate sums of the top k elements from ab with each element in c
	for i := 0; i < min(k, len(ab)); i++ {
		for j := 0; j < z; j++ {
			abc = append(abc, ab[i]+c[j])
		}
	}

	// Sort the resulting sums in descending order
	sort.Slice(abc, func(i, j int) bool {
		return abc[i] > abc[j]
	})

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
