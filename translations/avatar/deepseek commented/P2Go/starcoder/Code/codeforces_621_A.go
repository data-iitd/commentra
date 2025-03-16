
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements in the list
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of elements in the list: ")
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	// Read the list of integers
	fmt.Print("Enter the list of integers: ")
	input, _ = reader.ReadString('\n')
	lst := strings.Split(strings.TrimSpace(input), " ")
	var int_lst []int
	for _, v := range lst {
		int_lst = append(int_lst, int(v))
	}

	// Sort the list in ascending order
	sort.Ints(int_lst)

	// Reverse the list to get descending order
	for i := 0; i < len(int_lst)/2; i++ {
		int_lst[i], int_lst[len(int_lst)-i-1] = int_lst[len(int_lst)-i-1], int_lst[i]
	}

	// Initialize a counter for odd numbers
	od := 0
	for i := 0; i < len(int_lst); i++ {
		if int_lst[i]%2 == 1 {  // Check if the number is odd
			od += 1
		}
	}

	// Initialize sum to accumulate the result
	sum := 0
	ok := 0  // Initialize a flag to track if an odd number has been added

	// Iterate through the list to process each number
	for i := 0; i < len(int_lst); i++ {
		if int_lst[i]%2 == 0 {  // Check if the number is even
			sum += int_lst[i]  // Add even numbers to sum
		} else {
			if ok || od > 1 {  // Check if an odd number can be added
				sum += int_lst[i]  // Add odd number to sum
				od -= 1  // Decrement the count of odd numbers
				ok =!ok  // Toggle the flag
			}
		}
	}

	fmt.Println(sum)  // Print the final sum
}

