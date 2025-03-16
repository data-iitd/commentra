package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type FastReader struct {
	scanner *bufio.Scanner
}

func NewFastReader() *FastReader {
	return &FastReader{scanner: bufio.NewScanner(os.Stdin)}
}

func (fr *FastReader) Next() string {
	fr.scanner.Scan()
	return fr.scanner.Text()
}

func (fr *FastReader) NextInt() int {
	num, _ := strconv.Atoi(fr.Next())
	return num
}

func (fr *FastReader) NextLine() string {
	return fr.Next()
}

func solve() {
	scan := NewFastReader()
	t := scan.NextInt() // Read the number of test cases
	arr := make([]int, t) // Initialize a slice to store the elements
	for i := 0; i < t; i++ {
		arr[i] = scan.NextInt() // Read the elements of the array
	}
	prevWinner := 0 // Initialize the previous winner variable
	for i := 0; i < len(arr); i++ {
		if arr[i] == 1 { // Check if the current element is 1
			if prevWinner == 0 { // If no previous winner, set the winner to 2
				prevWinner = 2
			}
		}
		if prevWinner == 2 || prevWinner == 0 { // Check if the previous winner is 2 or unset
			if (arr[i]-1)%2 == 0 { // Check if the condition for player 2 is met
				fmt.Println(2) // Print the winner
				prevWinner = 2 // Update the previous winner
			} else {
				fmt.Println(1) // Print the winner
				prevWinner = 1 // Update the previous winner
			}
		} else { // If the previous winner is 1
			if (arr[i]-1)%2 == 0 { // Check if the condition for player 1 is met
				fmt.Println(1) // Print the winner
				prevWinner = 1 // Update the previous winner
			} else {
				fmt.Println(2) // Print the winner
				prevWinner = 2 // Update the previous winner
			}
		}
	}
}

func main() {
	solve()
}

// <END-OF-CODE>
