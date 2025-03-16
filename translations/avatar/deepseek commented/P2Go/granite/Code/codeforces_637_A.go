
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
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	s := strings.Split(reader.ReadLine()[2:], " ")

	// Create a map m from the list s
	m := make(map[string]int)
	for _, v := range s {
		m[v]++
	}

	// Reverse the list s
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}

	// Initialize two variables c and a to -1 and 0 respectively
	c, a := -1, 0

	// Iterate over the keys in the map m
	for _, v := range m {
		// Check if the value of the key is equal to the maximum value in the map m
		if v == max(m) {
			// Check if the index of the key in the reversed list s is greater than the current value of c
			if index(s, v) > c {
				// Update the value of a to the current key and update the value of c to the index of the current key in the reversed list s
				a = v
				c = index(s, v)
			}
		}
	}

	// Print the value of a
	fmt.Println(a)
}

func max(m map[string]int) int {
	max := 0
	for _, v := range m {
		if v > max {
			max = v
		}
	}
	return max
}

func index(s []string, v int) int {
	for i, val := range s {
		if v, _ := strconv.Atoi(val); v == v {
			return i
		}
	}
	return -1
}

