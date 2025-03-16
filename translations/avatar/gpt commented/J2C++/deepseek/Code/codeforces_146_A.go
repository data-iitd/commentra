package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Creating a Scanner object to read input from the user
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	
	// Initializing variables to hold the sum of the first half and the second half of the digits
	var x, y int
	var t int
	
	// Reading the length of the number and the number itself as a string
	var n int
	var str string
	fmt.Fscan(reader, &n)
	fmt.Fscan(reader, &str)
	
	// Converting the string to a slice of runes for easier manipulation
	l := []rune(str)
	
	// Checking if all characters in the string are either '4' or '7'
	for i := 0; i < n; i++ {
		if l[i] != '4' && l[i] != '7' {
			t = 1 // Set t to 1 if a character is found that is not '4' or '7'
		}
	}
	
	// If t is set, print "NO" indicating the number is not lucky
	if t == 1 {
		fmt.Fprintln(writer, "NO")
	} else {
		// Calculate the sum of the first half of the digits
		for i := 0; i < n / 2; i++ {
			x += int(l[i] - '0')
		}
		// Calculate the sum of the second half of the digits
		for i := n - 1; i > (n / 2) - 1; i-- {
			y += int(l[i] - '0')
		}
		// Compare the two sums and print "YES" if they are equal, otherwise print "NO"
		if x == y {
			fmt.Fprintln(writer, "YES")
		} else {
			fmt.Fprintln(writer, "NO")
		}
	}
}
