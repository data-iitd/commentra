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
	// Read the integer n and the list of strings s from standard input
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	s := strings.Split(readLine(reader), " ")

	// Create a map w from the list s
	w := make(map[string]int)
	for _, v := range s {
		w[v]++
	}

	// Reverse the list s
	s = s[::-1]

	// Initialize two variables c and a to -1 and 0 respectively
	c, a := -1, 0

	// Iterate over the items in the map w
	for k, v := range w {
		// Check if the count of the item is equal to the maximum count in the map w
		if v == max(w) {
			// Check if the index of the item in the reversed list s is greater than the current value of c
			if strings.Index(s, k) > c {
				// Update the value of a to the current item and update the value of c to the index of the current item in the reversed list s
				a = k
				c = strings.Index(s, k)
			}
		}
	}

	// Print the value of a
	fmt.Println(a)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func max(arr []int) int {
	max := arr[0]
	for _, v := range arr {
		if v > max {
			max = v
		}
	}
	return max
}

