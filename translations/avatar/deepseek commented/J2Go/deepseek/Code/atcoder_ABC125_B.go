package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	// Step 1: Read the input value `n` which represents the number of elements.
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Step 2: Read the values of `v` (values) and store them in a map `vList`.
	scanner.Scan()
	vStr := scanner.Text()
	vList := str2List(vStr)

	// Step 3: Read the values of `c` (costs) and store them in a map `cList`.
	scanner.Scan()
	cStr := scanner.Text()
	cList := str2List(cStr)

	// Step 4: Initialize a variable `max` to keep track of the maximum profit.
	var max int

	// Step 5: Iterate through the elements, calculate the profit for each element, and update `max` if the profit is positive.
	for i := 0; i < n; i++ {
		profit := vList[i] - cList[i]
		if profit > 0 {
			max += profit
		}
	}

	// Step 6: Print the maximum profit.
	fmt.Println(max)
}

// Helper method to convert a string of space-separated integers into a map with index as key and integer value as value.
func str2List(str string) map[int]int {
	vArrStr := strings.Split(str, " ")
	ret := make(map[int]int)
	for key, val := range vArrStr {
		num, _ := strconv.Atoi(val)
		ret[key] = num
	}
	return ret
}

