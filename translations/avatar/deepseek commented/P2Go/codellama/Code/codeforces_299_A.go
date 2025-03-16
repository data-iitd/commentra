
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the entire input, split the second line into a list of integers, and sort them.
	a := sort(strings.Split(readLine(1), " "))

	// Print the first element of the sorted list if it is divisible by any other element in the list, otherwise print -1.
	if any(x%a[0] for x in a) {
		fmt.Println(a[0])
	} else {
		fmt.Println(-1)
	}
}

func readLine(n int) string {
	reader := bufio.NewReader(os.Stdin)
	var line string
	for i := 0; i < n; i++ {
		line, _ = reader.ReadString('\n')
	}
	return line
}

func sort(arr []string) []int {
	var a []int
	for _, v := range arr {
		i, _ := strconv.Atoi(v)
		a = append(a, i)
	}
	return a
}

func any(iterable []int) bool {
	for _, v := range iterable {
		if v%a[0] == 0 {
			return true
		}
	}
	return false
}

// 