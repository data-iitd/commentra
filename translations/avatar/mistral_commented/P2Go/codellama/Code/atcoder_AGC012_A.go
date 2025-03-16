#######
# Import necessary libraries
#######

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

#######
# Function to read integers from the standard input
#######

func readInts() []int {
	var A []int
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		for _, s := range scanner.Text() {
			if s == ' ' {
				continue
			}
			i, _ := strconv.Atoi(string(s))
			A = append(A, i)
		}
	}
	return A
}

#######
# Main function
#######

func main() {
	n := 0
	fmt.Scan(&n)
	A := readInts()
	sort.Ints(A)
	ans := 0
	for i := len(A) - 2; i >= len(A)-2*n-1; i -= 2 {
		ans += A[i]
	}
	fmt.Println(ans)
}

#######
# Run the main function if the script is run as the main module
#######

if len(os.Args) == 1 {
	main()
}

