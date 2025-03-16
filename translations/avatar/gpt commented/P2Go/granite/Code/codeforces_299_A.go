
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
	// Define a lambda function to read an integer input
	num_inp := func() int {
		var num int
		fmt.Fscan(bufio.NewReader(os.Stdin), &num)
		return num
	}

	// Define a lambda function to read a list of integers from input
	arr_inp := func() []int {
		var arr []int
		fmt.Fscan(bufio.NewReader(os.Stdin), &arr)
		return arr
	}

	// Define a lambda function to read a space-separated list of integers as a map object
	sp_inp := func() map[int]bool {
		var sp_map = make(map[int]bool)
		for _, x := range strings.Split(num_inp(), " ") {
			num, _ := strconv.Atoi(x)
			sp_map[num] = true
		}
		return sp_map
	}

	// Read the input from the first line of the standard input, sort it, and convert it to a list of integers
	a := arr_inp()
	sort.Ints(a)

	// Check if any element in the list 'a' is not divisible by the first element of 'a'
	// If all elements are divisible, print the first element; otherwise, print -1
	if any(x%a[0]!= 0 for x := range a) {
		fmt.Println(-1)
	} else {
		fmt.Println(a[0])
	}
}

