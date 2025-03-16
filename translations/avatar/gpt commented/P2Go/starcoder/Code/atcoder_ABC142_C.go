package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Read the number of elements from user input
func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of elements: ")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))

	// Read the elements from user input, creating a list of tuples (index, value)
	A := make([][2]int, N)
	for i := 0; i < N; i++ {
		fmt.Print("Enter element ", i+1, ": ")
		A[i][0], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
		A[i][1], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}

	// Sort the list of tuples based on the second item (the value) in each tuple
	sort.Slice(A, func(i, j int) bool { return A[i][1] < A[j][1] })

	// Extract the first item (the original index) from each sorted tuple into a new list
	A_ := make([]int, N)
	for i := 0; i < N; i++ {
		A_[i] = A[i][0]
	}

	// Print the indices of the sorted values, separated by spaces
	for i := 0; i < N-1; i++ {
		fmt.Print(A_[i], " ")
	}
	fmt.Println(A_[N-1])
}

