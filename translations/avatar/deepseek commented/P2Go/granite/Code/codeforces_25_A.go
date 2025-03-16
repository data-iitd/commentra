

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d\n", &n)  // Read an integer input representing the number of elements
	input, _ := reader.ReadString('\n')  // Read the input string
	list := make([]int, n)  // Initialize an empty list of length n
	for i, v := range strings.Split(input, " ") {  // Split the input string, convert to integers, and store in the list
		list[i], _ = strconv.Atoi(v)
	}
	sum := 0  // Initialize the sum of the list
	for _, v := range list {  // Calculate the sum of the list
		sum += v % 2
	}
	if sum == 1 {  // Check if the sum of the list is 1
		fmt.Println(indexOf(list, 1) + 1)  // Print the index of the first occurrence of 1 (adjusted for 1-based indexing)
	} else {
		fmt.Println(indexOf(list, 0) + 1)  // Print the index of the first occurrence of 0 (adjusted for 1-based indexing)
	}
}

func indexOf(list []int, target int) int {  // Function to find the index of a target value in a list
	for i, v := range list {
		if v == target {
			return i
		}
	}
	return -1  // Return -1 if the target value is not found in the list
}

