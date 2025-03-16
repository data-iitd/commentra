package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	var a, b byte
	var res bool
	var arr [][2]byte
	var str [][2]byte

	// Reading the size of the matrix
	n, _ = strconv.Atoi(os.Args[1])

	// Initializing the 2D character array
	arr = make([][2]byte, n)
	str = make([][2]byte, n)

	// Reading n strings and storing them in the str array
	for i := 0; i < n; i++ {
		str[i] = []byte(os.Args[i+2])
	}

	// Populating the 2D character array from the strings
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			arr[i][j] = str[i][j]
		}
	}

	// Comparing the first two characters to determine a and b
	a = arr[0][0]
	b = arr[0][1]

	// If the characters are the same, print "NO" and exit
	if a == b {
		fmt.Println("NO")
		return
	}

	// Iterating through the matrix to validate the pattern
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i == j || i+j == n-1 { // Check diagonal elements
				if arr[i][j] != a { // If diagonal element is not a, set res to false
					res = false
					break
				}
			} else { // Check off-diagonal elements
				if arr[i][j] != b { // If off-diagonal element is not b, set res to false
					res = false
					break
				}
			}
		}
	}

	// Printing the result
	if res {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

