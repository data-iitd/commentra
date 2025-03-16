package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read an integer input which represents the size of the array
	y, _ := strconv.Atoi(readLine(reader))
	
	// Read a line of input, split it into individual strings, convert them to integers, and store them in a list
	arr := []int{}
	input, _ := reader.ReadString('\n')
	for _, s := range strings.Split(strings.TrimSpace(input), " ") {
		num, _ := strconv.Atoi(s)
		arr = append(arr, num)
	}
	
	// Iterate over each element in the array using index i
	for i := 0; i < len(arr); i++ {
		// Iterate over each element in the array using index j
		for j := 0; j < len(arr); j++ {
			// Skip the iteration if both indices are the same
			if i == j {
				continue
			}
			// Iterate over each element in the array using index k
			for k := 0; k < len(arr); k++ {
				// Check if the current element at index k is different from elements at indices i and j,
				// and if it is equal to the sum of the elements at indices i and j
				if arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i] + arr[j] {
					// Print the 1-based indices of the elements that satisfy the condition
					fmt.Println(k + 1, j + 1, i + 1)
					// Exit the program after finding the first valid triplet
					return
				}
			}
		}
	}
	
	// If no valid triplet is found, print -1
	fmt.Println(-1)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return string(str)
}
