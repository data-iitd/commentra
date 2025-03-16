package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Step 1: Take an integer input N, which represents the number of elements in the list.
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))

	// Step 2: Take a list of integers as input and store them in the list 'a'.
	a := make([]int, N)
	for i := 0; i < N; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}

	// Step 3: Calculate the total XOR of all elements in the list 'a' using reduce and XOR operator.
	total := 0
	for _, ai := range a {
		total ^= ai
	}

	// Step 4: Create a new list where each element is the XOR of the original element and the total.
	// Print the new list as a space-separated string.
	fmt.Println(strings.Trim(strings.Join(strings.Fields(fmt.Sprint(
		[]int(map(func(ai int) int {
			return ai ^ total
		}, a))),
	), " "), "[]"))
}

