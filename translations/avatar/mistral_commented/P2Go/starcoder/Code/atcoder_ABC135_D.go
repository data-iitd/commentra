
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read an integer
func readInt(bytes []byte, from int, val *int) int {
	i := from
	tmp := 0
	for i < len(bytes) && bytes[i]!='' {
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = tmp
	return i
}

// Function to read a string
func readNum(scanner *bufio.Scanner) (a int) {
	scanner.Scan()
	readInt(scanner.Bytes(), 0, &a)
	return
}

// Function to read a string
func readString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

// Function to read a list of integers
func readNNums(scanner *bufio.Scanner, n int) []int {
	res := make([]int, n)
	x := -1
	scanner.Scan()
	for i := 0; i < n; i++ {
		x = readInt(scanner.Bytes(), x+1, &res[i])
	}
	return res
}

// Function to read a list of strings
func readNStrings(scanner *bufio.Scanner, n int) []string {
	res := make([]string, n)
	x := -1
	scanner.Scan()
	for i := 0; i < n; i++ {
		x = readInt(scanner.Bytes(), x+1, &res[i])
	}
	return res
}

// Function to read a list of lists (2D array)
func readMatrix(scanner *bufio.Scanner, n, m int) [][]int {
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = readNNums(scanner, m)
	}
	return res
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of test cases
	t := readNum(scanner)

	// Iterate through all the test cases
	for i := 0; i < t; i++ {
		// Read the string S and its length n
		S := readString(scanner)
		n := len(S)

		// Base case: if the length of the string is 1
		if n == 1 {
			// Check if the string is '5' or '?' and print 1 if true, else print 0
			if S == "5" || S == "?" {
				fmt.Println(1)
			} else {
				fmt.Println(0)
				continue
			}
		}

		// Initialize a 2D array dp of size (n, 13) with all elements initialized to 0
		dp := make([][]int, n)
		for i := 0; i < n; i++ {
			dp[i] = make([]int, 13)
		}

		// Iterate through each index i from 0 to n-1
		for i := 0; i < n; i++ {
			// If i is the first index, process it differently
			if i == 0 {
				// If the character at index i is not '?', update the dp array accordingly
				if S[i]!= '?' {
					dp[i][int(S[i])-48] += 1
				}
				// If the character at index i is '?', update all elements in the dp array accordingly
				else {
					for j := 0; j < 10; j++ {
						dp[i][j] += 1
					}
				}
			}
			// If i is not the first index, process it differently
			else {
				// If the character at index i is not '?', update the dp array accordingly
				if S[i]!= '?' {
					for k := 0; k < 13; k++ {
						dp[i][(k*10+int(S[i])-48)%13] += dp[i-1][k]
					}
				}
				// If the character at index i is '?', update all elements in the dp array accordingly
				else {
					for j := 0; j < 10; j++ {
						for k := 0; k < 13; k++ {
							dp[i][(k*10+j)%13] += dp[i-1][k]
						}
					}
					// Update all elements in the dp array with the current value modulo mod
					for k := 0; k < 13; k++ {
						dp[i][k] %= 1000000007
					}
				}
			}
		}

		// Print the final answer, which is dp[n-1][5]
		fmt.Println(dp[n-1][5])
	}
}

