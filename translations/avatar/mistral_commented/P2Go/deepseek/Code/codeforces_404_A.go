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

	// Take the number of rows as input
	n, _ := strconv.Atoi(readLine(reader))

	// Initialize an empty list 's' to store the rows
	s := [][]string{}

	// Read each row and append it to the list 's'
	for i := 0; i < n; i++ {
		// Read a row as a string and convert it to a list
		k := strings.Split(readLine(reader), " ")
		// Append the list to the list 's'
		s = append(s, k)
	}

	// Initialize flags and empty lists 'd1' and 'd2'
	var flag bool
	d1 := []string{}
	d2 := []string{}
	rem := make(map[string]bool)

	// Iterate through each element in the list 's'
	for i := 0; i < n; i++ {
		// Iterate through each element in the same row and in the reverse order
		for j := 0; j < n; j++ {
			// If the current indices are same, append the element to 'd1'
			if i == j {
				d1 = append(d1, s[i][j])
			}
			// If the current indices are reverse of each other, append the element to 'd2'
			if i == n - j - 1 {
				d2 = append(d2, s[i][j])
			}
			// If the current indices are not same and not reverse, add the element to 'rem' set
			if i != j && i != n - j - 1 {
				rem[s[i][j]] = true
			}
		}
	}

	// Check if the size of 'rem' set is not equal to 1
	if len(rem) != 1 {
		// If the condition is true, print 'NO' and exit
		fmt.Println("NO")
		return
	}

	// Check if 'd1' and 'd2' lists are equal
	if !equalSlice(d1, d2) {
		// If the condition is true, print 'NO' and exit
		fmt.Println("NO")
		return
	}

	// Check if all elements in 'd1' are same
	if len(uniqueSlice(d1)) != 1 {
		// If the condition is true, print 'NO' and exit
		fmt.Println("NO")
		return
	}

	// Check if all elements in 'd1' are present in 'rem' set
	if uniqueSlice(d1)[0] == uniqueSlice(d1)[0] {
		// If the condition is true, print 'NO' and exit
		fmt.Println("NO")
		return
	}

	// If all the above conditions are false, print 'YES'
	fmt.Println("YES")
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return string(str)
}

func equalSlice(a, b []string) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func uniqueSlice(s []string) []string {
	uniqueMap := make(map[string]bool)
	for _, v := range s {
		uniqueMap[v] = true
	}
	uniqueSlice := []string{}
	for k := range uniqueMap {
		uniqueSlice = append(uniqueSlice, k)
	}
	return uniqueSlice
}
