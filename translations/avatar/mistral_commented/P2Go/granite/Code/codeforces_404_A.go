
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Take the number of rows as input
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0 : len(bufio.NewReader(os.Stdin).ReadLine())-1])

	// Initialize an empty list's' to store the rows
	s := make([][]string, n)

	// Read each row and append it to the list's'
	for i := 0; i < n; i++ {
		// Read a row as a string and convert it to a list
		k := strings.Split(bufio.NewReader(os.Stdin).ReadLine()[0 : len(bufio.NewReader(os.Stdin).ReadLine())-1], " ")
		// Append the list to the list's'
		s[i] = k
	}

	// Initialize flags and empty lists 'd1' and 'd2'
	flag := 0
	d1 := make([]string, n)
	d2 := make([]string, n)

	// Iterate through each element in the list's'
	for i := 0; i < n; i++ {
		// Iterate through each element in the same row and in the reverse order
		for j := 0; j < n; j++ {
			// If the current indices are same, append the element to 'd1'
			if i == j {
				d1[i] = s[i][j]
			}
			// If the current indices are reverse of each other, append the element to 'd2'
			if i == n-j {
				d2[i] = s[i][j]
			}
			// If the current indices are not same and not reverse, add the element to'rem' set
			if i!= j && i!= n-j {
				rem.Add(s[i][j])
			}
		}
	}

	// Check if the size of'rem' set is not equal to 1
	if len(rem)!= 1 {
		// If the condition is true, print 'NO' and exit
		fmt.Println("NO")
		return
	}

	// Check if 'd1' and 'd2' lists are equal
	if d1!= d2 {
		// If the condition is true, print 'NO' and exit
		fmt.Println("NO")
		return
	}

	// Check if all elements in 'd1' are same
	if len(set(d1))!= 1 {
		// If the condition is true, print 'NO' and exit
		fmt.Println("NO")
		return
	}

	// Check if all elements in 'd1' are present in'rem' set
	if set(d1) == rem {
		// If the condition is true, print 'NO' and exit
		fmt.Println("NO")
		return
	}

	// If all the above conditions are false, print 'YES'
	fmt.Println("YES")
}

