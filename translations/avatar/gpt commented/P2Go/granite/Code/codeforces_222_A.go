
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read two integers n and k from input
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	k, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Read a list of n integers from input
	elems := readLine(reader)
	split := strings.Split(elems, " ")
	var arr []int
	for _, s := range split {
		i, _ := strconv.Atoi(s)
		arr = append(arr, i)
	}

	// Define a lambda function to check if all elements in an array are the same
	allSame := func(arr []int) bool {
		for i := 1; i < len(arr); i++ {
			if arr[i]!= arr[0] {
				return false
			}
		}
		return true
	}

	// If all elements in elems are the same, print 0 and exit
	if allSame(arr) {
		fmt.Println(0)
		return
	}

	// If k is 1, it's impossible to satisfy the conditions, print -1 and exit
	if k == 1 {
		fmt.Println(-1)
		return
	}

	// If the last k-1 elements are not the same, print -1 and exit
	if!allSame(arr[len(arr)-k+1:]) {
		fmt.Println(-1)
		return
	}

	// Set the target value to the last element of elems
	target := arr[len(arr)-1]

	// Create a list of elements to delete, which are the first k-1 elements
	toDelete := arr[0 : k-1]

	// Remove elements from toDelete that are equal to the target from the end
	for len(toDelete) > 0 && toDelete[len(toDelete)-1] == target {
		toDelete = toDelete[:len(toDelete)-1]
	}

	// Print the number of elements that need to be deleted
	fmt.Println(len(toDelete))
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), " \r\n")
	}
	return ""
}

