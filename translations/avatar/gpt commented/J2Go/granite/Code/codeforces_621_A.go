
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
	// Reading input from the console
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of elements: ")
	n, _ := strconv.Atoi(reader.ReadLine())

	// Reading n long integers from input and storing them in a slice
	input := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Print("Enter element ", i+1, ": ")
		input[i], _ = strconv.ParseInt(reader.ReadLine(), 10, 64)
	}

	// Initializing a slice to store odd numbers and a variable to hold the sum
	odd := make([]int64, 0)
	sum := int64(0)

	// Iterating through the input slice to separate even and odd numbers
	for _, num := range input {
		if num%2 == 0 {
			// If the number is even, add it to the sum
			sum += num
		} else {
			// If the number is odd, add it to the odd slice
			odd = append(odd, num)
		}
	}

	// Sorting the odd slice in ascending order
	sort.Slice(odd, func(i, j int) bool {
		return odd[i] < odd[j]
	})

	// Adding all odd numbers to the sum
	for _, num := range odd {
		sum += num
	}

	// If the count of odd numbers is odd, subtract the smallest odd number from the sum
	if len(odd)%2!= 0 {
		sum -= odd[0]
	}

	// Printing the final calculated sum
	fmt.Println("The sum is:", sum)
}

