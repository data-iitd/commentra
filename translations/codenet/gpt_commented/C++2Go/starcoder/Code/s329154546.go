package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Read the number of strings (N) and the length of each string (L)
func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, &N, &L)

	// Declare an array to hold the strings
	S := make([]string, N)

	// Input the strings from the user
	for i := 0; i < N; i++ {
		fmt.Fscanln(reader, &S[i])
	}

	// Sort the array of strings in lexicographical order
	sort.Strings(S)

	// Output the sorted strings
	for i := 0; i < N; i++ {
		fmt.Println(S[i])
	}
}

