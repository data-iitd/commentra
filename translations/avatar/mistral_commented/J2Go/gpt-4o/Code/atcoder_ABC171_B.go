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
	// Create a new reader for input
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input
	line, _ := reader.ReadString('\n')
	tokens := strings.Fields(line)

	// Parse n and k
	n, _ := strconv.Atoi(tokens[0])
	k, _ := strconv.Atoi(tokens[1])

	// Read the array a
	a := make([]int, n)
	line, _ = reader.ReadString('\n')
	tokens = strings.Fields(line)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(tokens[i])
	}

	// Sort the array a
	sort.Ints(a)

	// Calculate the answer: sum of first k elements of sorted array a
	ans := 0
	for i := 0; i < k; i++ {
		ans += a[i]
	}

	// Print the answer
	fmt.Println(ans)
}

// <END-OF-CODE>
