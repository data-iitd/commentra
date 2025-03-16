
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Take an integer 'n' as input
	nTemp, err := reader.ReadString('\n')
	checkError(err)
	n, err := strconv.Atoi(strings.TrimSpace(nTemp))
	checkError(err)

	// Initialize a list 'a' of 'n' integers by taking input
	aTemp, err := reader.ReadString('\n')
	checkError(err)
	aTemp = strings.TrimSpace(aTemp)
	a := strings.Split(aTemp, " ")
	aSlice := make([]int, n)
	for i, aTemp := range a {
		aSlice[i], err = strconv.Atoi(aTemp)
		checkError(err)
	}

	// Initialize an empty list 'b' of length 'n'
	b := make([]int, n)

	// Assign indices to 'b' based on the values in 'a'
	for i, aTemp := range aSlice {
		// Assign index 'i' to the position 'a[i] - 1' in list 'b'
		b[aTemp-1] = i
	}

	// Initialize a variable'res' to 0
	res := 0

	// Calculate the absolute difference between consecutive indices in 'b' and sum them up
	for i := 1; i < n; i++ {
		// Add the absolute difference between indices 'i' and 'i-1' to'res'
		res += abs(b[i]-b[i-1])
	}

	// Print the final result'res'
	fmt.Println(res)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

