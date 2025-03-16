package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	// Creating a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Reading the number of elements to be processed
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	
	// Initializing a list to store the input numbers
	var list []int64
	
	// Reading n long integers from input and adding them to the list
	for i := 0; i < n; i++ {
		scanner.Scan()
		num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
		list = append(list, num)
	}
	
	// Initializing a list to store odd numbers and a variable to hold the sum
	var odd []int64
	var sum int64 = 0
	
	// Iterating through the list to separate even and odd numbers
	for _, i := range list {
		if i % 2 == 0 {
			// If the number is even, add it to the sum
			sum += i
		} else {
			// If the number is odd, add it to the odd list
			odd = append(odd, i)
		}
	}
	
	// Sorting the list of odd numbers in ascending order
	sort.Slice(odd, func(i, j int) bool {
		return odd[i] < odd[j]
	})
	
	// Adding all odd numbers to the sum
	for _, i := range odd {
		sum += i
	}
	
	// If the count of odd numbers is odd, subtract the smallest odd number from the sum
	if len(odd) % 2 != 0 {
		sum -= odd[0]
	}
	
	// Printing the final calculated sum
	fmt.Println(sum)
}
