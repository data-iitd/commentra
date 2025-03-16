package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Reading input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Reading the size of the matrix (n x n)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Initializing a 2D character array to store the matrix
	arr := make([][]byte, n)
	for i := range arr {
		arr[i] = make([]byte, n)
	}

	// Initializing a String array to store the input strings
	str := make([]string, n)

	// Reading n strings from the input
	for i := 0; i < n; i++ {
		str[i], _ = reader.ReadString('\n')
	}

	// Filling the 2D character array with characters from the input strings
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			arr[i][j] = str[i][j]
		}
	}

	// Storing the first two characters of the matrix for comparison
	a := arr[0][0]
	b := arr[0][1]

	// Checking if the first two characters are the same
	if a == b {
		fmt.Println("NO") // If they are the same, print "NO"
	} else {
		// Initializing a boolean variable to track the result
		res := true

		// Checking the conditions for the characters in the matrix
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				// Checking if the current position is on the main diagonal or the anti-diagonal
				if i == j || i+j == n-1 {
					// If it is, check if the character matches 'a'
					if arr[i][j]!= a {
						res = false // If not, set result to false and break
						break
					}
				} else {
					// If it is not on the diagonals, check if the character matches 'b'
					if arr[i][j]!= b {
						res = false // If not, set result to false and break
						break
					}
				}
			}
		}

		// Print "YES" if the conditions are satisfied, otherwise print "NO"
		if res {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

