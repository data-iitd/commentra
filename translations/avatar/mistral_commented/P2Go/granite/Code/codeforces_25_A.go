
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read user input and assign it to the variable 'n'
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])

	// Create a list 'list' with the same length as 'n'
	// Each element in the list is the remainder of the corresponding input value divided by 2
	list := make([]int, n)
	for i := 0; i < n; i++ {
		list[i], _ = strconv.Atoi(strings.Split(reader.ReadLine(), " ")[i]) % 2
	}

	// Check if the sum of all elements in the list is equal to 1
	if sum := sum(list); sum == 1 {
		// If the condition is true, print the index of the first occurrence of the number 1 in the list
		fmt.Println("The first number with remainder 1 is:", find(list, 1))
	} else {
		// If the condition is false, print the index of the first occurrence of the number 0 in the list
		fmt.Println("The first number with remainder 0 is:", find(list, 0))
	}
}

func sum(list []int) int {
	sum := 0
	for _, v := range list {
		sum += v
	}
	return sum
}

func find(list []int, target int) int {
	for i, v := range list {
		if v == target {
			return i + 1
		}
	}
	return -1
}

