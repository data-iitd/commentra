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
	n, _ := strconv.Atoi(readLine(reader))

	// Read a line of input, split it into individual elements, convert them to integers,
	// and create a list that contains 1 for odd numbers and 0 for even numbers
	list := []int{}
	input, _ := reader.ReadString('\n')
	elements := strings.Split(strings.TrimSpace(input), " ")
	for _, x := range elements {
		num, _ := strconv.Atoi(x)
		list = append(list, num%2)
	}

	// Check if there is exactly one odd number in the list
	oddCount := 0
	for _, val := range list {
		if val == 1 {
			oddCount++
		}
	}

	if oddCount == 1 {
		// If there is one odd number, print its position (1-based index)
		for i, val := range list {
			if val == 1 {
				fmt.Println(i + 1)
				break
			}
		}
	} else {
		// If there are no odd numbers, print the position of the first even number (1-based index)
		for i, val := range list {
			if val == 0 {
				fmt.Println(i + 1)
				break
			}
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return string(str)
}
