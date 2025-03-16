
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Assigning the values of input variables to n, a, and b
	reader := bufio.NewReader(os.Stdin)
	n, a, b := readThreeInt64FromInput(reader)

	// Creating two lists, lista and listb, from the input
	lista := readNInt64FromInput(reader, a)
	listb := readNInt64FromInput(reader, b)

	// Iterating through the range of n
	for k := int64(0); k < n; k++ {
		// Checking if k+1 is present in the lista list
		if contains(lista, k+1) {
			// Printing 1 if k+1 is present in the lista list
			fmt.Print(1, " ")
		} else {
			// Printing 2 if k+1 is not present in the lista list
			fmt.Print(2, " ")
		}
	}
	fmt.Println()
}

func readThreeInt64FromInput(reader *bufio.Reader) (int64, int64, int64) {
	line, _, err := reader.ReadLine()
	if err!= nil {
		panic(err)
	}

	parts := strings.Split(string(line), " ")

	a, err := strconv.ParseInt(parts[0], 10, 64)
	checkError(err)
	b, err := strconv.ParseInt(parts[1], 10, 64)
	checkError(err)
	c, err := strconv.ParseInt(parts[2], 10, 64)
	checkError(err)

	return a, b, c
}

func readNInt64FromInput(reader *bufio.Reader, n int64) []int64 {
	res := make([]int64, n)
	for i := int64(0); i < n; i++ {
		val, err := reader.readInt64()
		res[i] = val
		checkError(err)
	}

	return res
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

func contains(s []int64, e int64) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

