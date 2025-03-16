package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a Scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Declare variables for the number of elements and sizes of the two lists
	var n, a, b int

	// Read the values for n, a, and b from the input
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	a, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	b, _ = strconv.Atoi(sc.Text())

	// Initialize two ArrayLists to store the elements of the two lists
	list1 := make([]int, a)
	list2 := make([]int, b)

	// Read 'a' integers into list1
	for i := 0; i < a; i++ {
		sc.Scan()
		list1[i], _ = strconv.Atoi(sc.Text())
	}

	// Read 'b' integers into list2
	for i := 0; i < b; i++ {
		sc.Scan()
		list2[i], _ = strconv.Atoi(sc.Text())
	}

	// Iterate from 0 to n-1 to check the presence of each index in list1
	for i := 0; i < n; i++ {
		// If the current index + 1 is in list1, print 1
		if big.NewInt(int64(i+1)).IsInt64() {
			fmt.Printf("%d ", 1)
		} else {
			// Otherwise, print 2
			fmt.Printf("%d ", 2)
		}
	}
}

