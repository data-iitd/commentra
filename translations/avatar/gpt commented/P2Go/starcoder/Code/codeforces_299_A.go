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
	// Read the input from the first line of the standard input, sort it, and convert it to a list of integers
	a := sort.IntSlice(strings.Fields(bufio.NewScanner(os.Stdin).Scan()[1]))

	// Check if any element in the list 'a' is not divisible by the first element of 'a'
	// If all elements are divisible, print the first element; otherwise, print -1
	fmt.Println([a[0], -1][any(x%a[0] == 0 for x := range a)])
}

