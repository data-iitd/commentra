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
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the first line of input
	line, err := reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}
	// Convert the string into a list of integers
	arr := strings.Split(line, " ")
	// Convert the list of strings into a list of integers
	arr = convertStringArrayToInt(arr)
	// The first element is the total length of the ribbon
	length := arr[0]
	// Sort the next three elements (the lengths of the pieces) in ascending order
	arr = sortArray(arr[1:4])
	// If the total length is divisible by the smallest piece length, print the maximum number of pieces
	if (length % arr[0] == 0) {
		fmt.Println(length / arr[0])
		return
	}
	// Initialize the answer variable to keep track of the maximum pieces
	ans := 0
	// Case when the two smallest piece lengths are equal
	if (arr[0] == arr[1]) {
		k := 0
		// Iterate through the number of the largest pieces that can fit into the ribbon
		for i := 0; i <= int(length/arr[2]); i++ {
			// Calculate the remaining length after using i pieces of the largest size
			check := length - i*arr[2]
			// Check if the remaining length can be completely divided by the smallest piece length
			if (check >= 0 && check % arr[0] == 0) {
				k = check / arr[0]
				// Update the maximum pieces found
				ans = max(ans, k+i)
			}
		}
	} else {
		// Case when the two smallest piece lengths are different
		k := 0
		// Iterate through the number of the largest pieces that can fit into the ribbon
		for i := 0; i <= int(length/arr[2]); i++ {
			// Iterate through the number of the second largest pieces that can fit into the ribbon
			for j := 0; j <= int(length/arr[1]); j++ {
				// Calculate the remaining length after using i pieces of the largest size and j pieces of the second largest size
				check := length - i*arr[2] - j*arr[1]
				// Check if the remaining length can be completely divided by the smallest piece length
				if (check >= 0 && check % arr[0] == 0) {
					k = check / arr[0]
					// Update the maximum pieces found
					ans = max(ans, k+i+j)
				}
			}
		}
	}
	// Print the maximum number of pieces that can be obtained
	fmt.Println(ans)
}

// Convert an array of strings into an array of integers
func convertStringArrayToInt(arr []string) []int {
	var newArr []int
	for _, v := range arr {
		val, _ := strconv.Atoi(v)
		newArr = append(newArr, val)
	}
	return newArr
}

// Sort an array in ascending order
func sortArray(arr []int) []int {
	sort.Ints(arr)
	return arr
}

// Return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// END-OF-CODE
