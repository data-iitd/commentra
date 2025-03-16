

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
	var num, k int
	var err error
	var arr []int
	var different map[int]bool
	var temp int

	// Read the number of elements and the divisor
	input := strings.Split(readLine(reader), " ")
	num, err = strconv.Atoi(input[0])
	checkError(err)
	k, err = strconv.Atoi(input[1])
	checkError(err)

	// Read the array of integers
	input = strings.Split(readLine(reader), " ")
	for i := 0; i < num; i++ {
		x, err := strconv.Atoi(input[i])
		checkError(err)
		arr = append(arr, x)
	}

	// Initialize a set to keep track of unique elements not divisible by k
	different = make(map[int]bool)

	// Sort the array
	sort(arr)

	// Iterate through each element in the sorted array
	for _, x := range arr {
		if x%k!= 0 ||!different[x/k] { // Check if x is not divisible by k or x//k is not in the set
			different[x] = true // Add x to the set if the condition is true
		}
		temp = max(len(different), temp) // Update temp with the maximum length of the set
	}

	fmt.Println(temp) // Print the maximum number of unique elements not divisible by k
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), " \r\n")
	}
	return ""
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func sort(arr []int) {
	// Implement your sorting algorithm here
}

