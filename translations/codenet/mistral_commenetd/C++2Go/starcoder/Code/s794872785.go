<<<<<<< HEAD


import (
	"bufio"
	"fmt"
	"os"
	"strconv"
=======
package main

import (
	"fmt"
	"os"
>>>>>>> 98c87cb78a (data updated)
	"strings"
)

// Function to solve the problem
func solve() bool {
	// Initialize variables
	var maxsize int = 0
	var maxcnt int = 0
	var ans_num int = -1
	var ans_num2 int = -1
	var str_v []string

	// Read strings from input
<<<<<<< HEAD
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		// Push the string into the vector
		str_v = append(str_v, scanner.Text())
		// Update maxsize if the current string is larger
		if maxsize < len(scanner.Text()) {
			maxsize = len(scanner.Text())
=======
	var in string
	for {
		if _, err := fmt.Scanf("%s", &in); err!= nil {
			break
		}
		// Push the string into the vector
		str_v = append(str_v, in)
		// Update maxsize if the current string is larger
		if maxsize < len(in) {
			maxsize = len(in)
>>>>>>> 98c87cb78a (data updated)
			ans_num = len(str_v) - 1
		}
	}

	// Find the string with maximum occurrences in the vector
	for i := 0; i < len(str_v); i++ {
<<<<<<< HEAD
		cnt := 0
=======
		var cnt int = 0
>>>>>>> 98c87cb78a (data updated)
		// Count the occurrences of the current string in the vector
		for j := 0; j < len(str_v); j++ {
			if str_v[i] == str_v[j] {
				cnt++
			}
		}
		// Update maxcnt and ans_num2 if the current string has more occurrences
		if maxcnt < cnt {
			maxcnt = cnt
			ans_num2 = i
		}
	}

	// Print the answer
<<<<<<< HEAD
	fmt.Println(str_v[ans_num2], " ", str_v[ans_num])
=======
	fmt.Printf("%s %s\n", str_v[ans_num2], str_v[ans_num])
>>>>>>> 98c87cb78a (data updated)

	// Return true to indicate successful execution
	return true
}

// Main function
func main() {
<<<<<<< HEAD
	// Set the precision of cout to 10 decimal places
=======
	// Set the precision of fmt to 10 decimal places
>>>>>>> 98c87cb78a (data updated)
	fmt.Printf("%.10f\n", 1.23456789)
	// Call the solve function
	solve()
}

