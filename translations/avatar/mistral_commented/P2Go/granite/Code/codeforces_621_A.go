
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Take an integer 'n' as input
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[2 : len(bufio.NewReader(os.Stdin).ReadLine())])

	// Create a list 'lst' of 'n' integers taken as input
	lst := make([]int, n)
	for i := 0; i < n; i++ {
		lst[i], _ = strconv.Atoi(strings.Split(bufio.NewReader(os.Stdin).ReadLine(), " ")[i])
	}

	// Sort the list 'lst' in ascending order
	for i := 0; i < n; i++ {
		for j := 0; j < n-i-1; j++ {
			if lst[j] > lst[j+1] {
				lst[j], lst[j+1] = lst[j+1], lst[j]
			}
		}
	}

	// Reverse the sorted list 'lst'
	for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
		lst[i], lst[j] = lst[j], lst[i]
	}

	// Initialize odd_digits counter 'od' to 0
	od := 0

	// Iterate through each integer 'i' in the list 'lst'
	for i := 0; i < n; i++ {
		// If the integer 'i' has an odd number of bits (1 in binary representation), increment 'od' counter
		if lst[i]%2 == 1 {
			od++
		}
	}

	// Initialize sum and ok variables
	sum := 0
	ok := false

	// Iterate through each index 'i' in the range of 'n'
	for i := 0; i < n; i++ {
		// If the integer at index 'i' in the list 'lst' is even, add it to the sum'sum'
		if lst[i]%2 == 0 {
			sum += lst[i]
		} else {
			// If the integer at index 'i' in the list 'lst' is odd and either 'ok' is True or 'od' is greater than 1, add it to the sum'sum' and toggle 'ok'
			if ok || od > 1 {
				sum += lst[i]
				od--
				ok =!ok
			}
		}
	}

	// Print the final sum
	fmt.Println(sum)
}
