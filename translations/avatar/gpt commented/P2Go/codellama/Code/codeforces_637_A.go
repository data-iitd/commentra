package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements
	n, _ := strconv.Atoi(readLine(os.Stdin))

	// Read the input string, remove the last character (newline), and split it into a list
	s := strings.Split(readLine(os.Stdin)[:len(readLine(os.Stdin))-1], " ")

	// Count the occurrences of each element in the list
	w := make(map[string]int)
	for _, v := range s {
		w[v]++
	}

	// Reverse the list to process elements in reverse order
	s = reverse(s)

	// Initialize variables to track the index of the most frequent element and its value
	c, a := -1, ""

	// Iterate through each unique element in the count dictionary
	for i := range w {
		// Check if the current element's count is equal to the maximum count
		if w[i] == max(w) {
			// If the index of the current element in the reversed list is greater than the current index
			if indexOf(s, i) > c {
				// Update the most frequent element and its index
				a = i
				c = indexOf(s, i)
			}
		}
	}

	// Print the most frequent element that appears last in the original order
	fmt.Println(a)
}

func readLine(file *os.File) string {
	reader := bufio.NewReader(file)
	var line string
	for {
		l, isPrefix, err := reader.ReadLine()
		line += string(l)
		if !isPrefix || err != nil {
			break
		}
	}
	return line
}

func reverse(s []string) []string {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
	return s
}

func indexOf(s []string, e string) int {
	for i, v := range s {
		if v == e {
			return i
		}
	}
	return -1
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

// 