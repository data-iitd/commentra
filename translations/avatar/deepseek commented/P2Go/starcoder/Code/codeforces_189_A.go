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
	// Convert the string to a list of integers
	arr := strings.Split(line, " ")
	// Convert the list of strings to a list of integers
	arr = convertToInt(arr)
	// Assign the first integer in the input list to the variable 'length'
	length := arr[0]
	// Sort the remaining three integers in ascending order and assign to 'arr'
	arr = sort.IntSlice(arr[1:4])
	sort.Sort(arr)
	// Check if 'length' is perfectly divisible by the largest integer in 'arr'
	if length%arr[0] == 0 {
		// Print the quotient and return if true
		fmt.Println(length / arr[0])
		return
	}
	// Initialize 'ans' to 0 for storing the maximum number of ribbons
	ans := 0
	// If the two smaller integers are equal, proceed with this block
	if arr[0] == arr[1] {
		k := 0
		// Iterate through possible combinations of the two smaller integers
		for i := 0; i <= int(length/arr[2]); i++ {
			check := length - i*arr[2]
			if check >= 0 && check%arr[0] == 0 {
				k = check / arr[0]
				ans = max(ans, k+i)
			}
		}
	} else {
		// If the two smaller integers are not equal, iterate through all three integers
		k := 0
		for i := 0; i <= int(length/arr[2]); i++ {
			for j := 0; j <= int(length/arr[1]); j++ {
				check := length - i*arr[2] - j*arr[1]
				if check >= 0 && check%arr[0] == 0 {
					k = check / arr[0]
					ans = max(ans, k+i+j)
				}
			}
		}
	}
	// Print the maximum number of ribbons that can be cut and return
	fmt.Println(ans)
	return
}

func convertToInt(arr []string) []int {
	var newArr []int
	for _, v := range arr {
		val, _ := strconv.Atoi(v)
		newArr = append(newArr, val)
	}
	return newArr
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

