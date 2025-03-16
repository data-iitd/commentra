package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n := 0
	fmt.Sscanf(scanner.Text(), "%d", &n)

	// Allocating memory for the 2D char array and the String array
	arr := make([][]byte, n)
	str := make([]string, n)

	// Reading the strings from the standard input stream and storing them in the String array
	for i := 0; i < n; i++ {
		scanner.Scan()
		str[i] = scanner.Text()
	}

	// Converting each String to a 2D char array and storing it in the corresponding position of the 2D char array
	for i := 0; i < n; i++ {
		arr[i] = make([]byte, n)
		for j := 0; j < n; j++ {
			arr[i][j] = str[i][j]
		}
	}

	// Initializing two variables 'a' and 'b' with the characters at the first position of the first row of the 2D char array
	a := arr[0][0]
	b := arr[0][1]

	// Checking if the first characters of the first row are equal or not
	if a == b {
		fmt.Println("NO")
	} else {
		res := true

		// Checking if there exists any pair of distinct characters in the 2D char array such that they form a diagonal line
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				// Checking if the current pair (i, j) and (j, i) form a diagonal line
				if (i == j || i+j == n-1) {
					// Checking if the characters at the current position of the 2D char array are equal to 'a' or 'b'
					if arr[i][j] != a {
						res = false
						break
					}
				} else {
					// Checking if the characters at the current position of the 2D char array are equal to 'b'
					if arr[i][j] != b {
						res = false
						break
					}
				}
			}
		}

		// Printing "YES" if all the characters in the 2D char array form either a single diagonal line of 'a's and 'b's or two separate diagonal lines of 'a's and 'b's
		if res {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
