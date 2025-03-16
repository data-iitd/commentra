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
	// Initialize input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read input: number of elements n and the number of summands k
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(parts[0])
	k, _ := strconv.Atoi(parts[1])

	// Read input array a of size n
	a := make([]int, n)
	input, _ = reader.ReadString('\n')
	parts = strings.Split(strings.TrimSpace(input), " ")
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(parts[i])
	}

	// Sort the array a using sort.Ints
	sort.Ints(a)

	// Calculate the answer: sum of first k elements of sorted array a
	ans := 0
	for i := 0; i < k; i++ {
		ans += a[i]
	}

	// Write the answer to the output stream
	fmt.Fprintln(writer, ans)
}
