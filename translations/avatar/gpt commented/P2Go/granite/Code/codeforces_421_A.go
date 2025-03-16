
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read three integers from input: n (number of elements), a, and b
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	split := strings.Split(input, " ")
	n, _ := strconv.Atoi(split[0])
	a, _ := strconv.Atoi(split[1])
	b, _ := strconv.Atoi(split[2])

	// Read a list of integers from input and store it in lista
	input, _ = reader.ReadString('\n')
	input = strings.TrimSpace(input)
	split = strings.Split(input, " ")
	lista := make([]int, n)
	for i := 0; i < n; i++ {
		lista[i], _ = strconv.Atoi(split[i])
	}

	// Read another list of integers from input and store it in listb
	input, _ = reader.ReadString('\n')
	input = strings.TrimSpace(input)
	split = strings.Split(input, " ")
	listb := make([]int, n)
	for i := 0; i < n; i++ {
		listb[i], _ = strconv.Atoi(split[i])
	}

	// Iterate through the range of n (from 0 to n-1)
	for k := 0; k < n; k++ {
		// Check if the current index + 1 is present in lista
		if contains(lista, k+1) {
			// If present, print 1 followed by a space
			fmt.Print(1, " ")
		} else {
			// If not present, print 2 followed by a space
			fmt.Print(2, " ")
		}
	}
	fmt.Println()
}

func contains(s []int, e int) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

