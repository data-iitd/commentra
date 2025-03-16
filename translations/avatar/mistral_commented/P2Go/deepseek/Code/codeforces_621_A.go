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

	// Read integer 'n'
	n, _ := strconv.Atoi(readLine(reader))

	// Read list 'lst' of 'n' integers
	lstStr, _ := reader.ReadString('\n')
	lstStr = strings.TrimSpace(lstStr)
	lstStrSlice := strings.Split(lstStr, " ")
	lst := make([]int, n)
	for i := 0; i < n; i++ {
		lst[i], _ = strconv.Atoi(lstStrSlice[i])
	}

	// Sort the list 'lst' in ascending order
	sort.Ints(lst)

	// Reverse the sorted list 'lst'
	for i, j := 0, len(lst)-1; i < j; i, j = i+1, j-1 {
		lst[i], lst[j] = lst[j], lst[i]
	}

	// Initialize odd_digits counter 'od' to 0
	od := 0

	// Iterate through each integer 'i' in the list 'lst'
	for _, i := range lst {
		// If the integer 'i' has an odd number of bits (1 in binary representation), increment 'od' counter
		if i&1 != 0 {
			od += 1
		}
	}

	// Initialize sum and ok variables
	sum := 0
	ok := false

	// Iterate through each index 'i' in the range of 'n'
	for i := 0; i < n; i++ {
		// If the integer at index 'i' in the list 'lst' is even, add it to the sum 'sum'
		if lst[i]%2 == 0 {
			sum += lst[i]
		} else {
			if ok || od > 1 {
				sum += lst[i]
				od -= 1
				ok = !ok
			}
		}
	}

	// Print the final sum
	fmt.Println(sum)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return strings.TrimSpace(string(str))
}
