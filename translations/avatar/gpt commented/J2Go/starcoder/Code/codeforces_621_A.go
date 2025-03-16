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
	// Reading input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Reading the number of elements to be processed
	n, _ := strconv.Atoi(readLine(reader))

	// Initializing a list to store the input numbers
	list := make([]int, n)

	// Reading n long integers from input and adding them to the list
	for i := 0; i < n; i++ {
		list[i], _ = strconv.Atoi(readLine(reader))
	}

	// Initializing a list to store odd numbers and a variable to hold the sum
	odd := make([]int, 0)
	sum := 0

	// Iterating through the list to separate even and odd numbers
	for _, i := range list {
		if i%2 == 0 {
			// If the number is even, add it to the sum
			sum += i
		} else {
			// If the number is odd, add it to the odd list
			odd = append(odd, i)
		}
	}

	// Sorting the list of odd numbers in ascending order
	sort.Ints(odd)

	// Adding all odd numbers to the sum
	for _, i := range odd {
		sum += i
	}

	// If the count of odd numbers is odd, subtract the smallest odd number from the sum
	if len(odd)%2!= 0 {
		sum -= odd[0]
	}

	// Printing the final calculated sum
	fmt.Println(sum)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

