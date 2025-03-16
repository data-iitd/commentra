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
	reader := bufio.NewReader(os.Stdin)
	
	// Read two integers from input: num (number of elements) and k (the divisor)
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	num, _ := strconv.Atoi(parts[0])
	k, _ := strconv.Atoi(parts[1])
	
	// Read the array of integers from input
	input, _ = reader.ReadString('\n')
	arrStr := strings.Split(strings.TrimSpace(input), " ")
	arr := make([]int, num)
	for i, str := range arrStr {
		arr[i], _ = strconv.Atoi(str)
	}
	
	// Initialize a map to keep track of unique elements that meet the criteria
	different := make(map[int]bool)
	
	// Initialize a variable to keep track of the maximum size of the 'different' map
	var temp int
	
	// Sort the array to process elements in ascending order
	sort.Ints(arr)
	
	// Iterate through each element in the sorted array
	for _, x := range arr {
		// Check if the element is not divisible by k or if its quotient is not already in the 'different' map
		if x % k != 0 || !different[x / k] {
			// Add the element to the 'different' map since it meets the criteria
			different[x] = true
		}
		
		// Update the maximum size of the 'different' map if the current size is larger
		if len(different) > temp {
			temp = len(different)
		}
	}
	
	// Print the maximum size of the 'different' map found
	fmt.Println(temp)
}
