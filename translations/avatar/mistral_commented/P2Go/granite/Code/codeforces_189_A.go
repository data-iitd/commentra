
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Function to find the maximum number of pieces that can be cut from a ribbon of given length

	// Create a new scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the first line of input, which contains the length of the ribbon
	scanner.Scan()
	length, _ := strconv.Atoi(scanner.Text())

	// Read the next three lines of input, which represent the lengths of the three pieces of ribbon
	var arr [3]int
	for i := 0; i < 3; i++ {
		scanner.Scan()
		arr[i], _ = strconv.Atoi(scanner.Text())
	}

	// Sort the three elements of the array in ascending order
	for i := 0; i < 3; i++ {
		for j := i + 1; j < 3; j++ {
			if arr[i] > arr[j] {
				arr[i], arr[j] = arr[j], arr[i]
			}
		}
	}

	// Check if the length of the ribbon is divisible by the first element of the sorted array
	if length%arr[0] == 0 {
		// If it is, print the number of pieces required and return
		fmt.Println(length / arr[0])
		return
	}

	// Initialize an answer variable to keep track of the maximum number of pieces that can be cut
	ans := 0

	// If the first two elements of the sorted array are equal
	if arr[0] == arr[1] {
		// Initialize a variable k to keep track of the number of pieces required
		k := 0

		// Loop to find the maximum number of pieces that can be cut from the ribbon
		for i := 0; i <= length/arr[2]; i++ {
			// Check if the remaining length after subtracting i * arr[2] is divisible by arr[0]
			check := length - i*arr[2]
			if check >= 0 && check%arr[0] == 0 {
				// If it is, update the answer and k
				k = check / arr[0]
				ans = int(max(float64(ans), float64(k+i)))
			}
		}
	} else {
		// Initialize a variable k to keep track of the number of pieces required
		k := 0

		// Double loop to find the maximum number of pieces that can be cut from the ribbon
		for i := 0; i <= length/arr[2]; i++ {
			for j := 0; j <= length/arr[1]; j++ {
				// Check if the remaining length after subtracting i * arr[2] and j * arr[1] is divisible by arr[0]
				check := length - i*arr[2] - j*arr[1]
				if check >= 0 && check%arr[0] == 0 {
					// If it is, update the answer and k
					k = check / arr[0]
					ans = int(max(float64(ans), float64(k+i+j)))
				}
			}
		}
	}

	// Print the final answer and return
	fmt.Println(ans)
}

func max(a, b float64) float64 {
	if a > b {
		return a
	}
	return b
}

