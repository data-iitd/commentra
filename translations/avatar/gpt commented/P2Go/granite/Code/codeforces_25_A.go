
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

	// Read an integer input which represents the number of elements
	nTemp, err := reader.ReadString('\n')
	checkError(err)
	n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
	checkError(err)

	// Read a line of input, split it into individual elements, convert them to integers,
	// and create a list that contains 1 for odd numbers and 0 for even numbers
	listTemp, err := reader.ReadString('\n')
	checkError(err)
	listTemp = strings.TrimSpace(listTemp)
	list := strings.Split(listTemp, " ")
	var listInt []int
	for _, v := range list {
		listInt = append(listInt, int(mustParseInt(v)))
	}

	// Check if there is exactly one odd number in the list
	oddCount := 0
	for _, v := range listInt {
		if v%2 == 1 {
			oddCount++
		}
	}
	if oddCount == 1 {
		// If there is one odd number, print its position (1-based index)
		for i, v := range listInt {
			if v%2 == 1 {
				fmt.Println(i + 1)
				break
			}
		}
	} else {
		// If there are no odd numbers, print the position of the first even number (1-based index)
		for i, v := range listInt {
			if v%2 == 0 {
				fmt.Println(i + 1)
				break
			}
		}
	}
}

func mustParseInt(s string) int {
	i, err := strconv.Atoi(s)
	if err!= nil {
		panic(err)
	}
	return i
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

