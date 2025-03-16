package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	// Creating a Scanner object to read input from the user
	in := bufio.NewScanner(os.Stdin)

	// Initializing variables to hold the sum of the first half and the second half of the digits
	x := 0
	y := 0
	t := 0 // Variable to check if there are any digits other than '4' or '7'

	// Reading the length of the number and the number itself as a string
	var n int
	in.Scan()
	n, _ = strconv.Atoi(in.Text())
	in.Scan()
	str := in.Text()

	// Converting the string to a character array for easier manipulation
	l := []rune(str)

	// Checking if all characters in the string are either '4' or '7'
	for i := 0; i < n; i++ {
		if l[i] != '4' && l[i] != '7' {
			t = 1 // Set t to 1 if a character is found that is not '4' or '7'
		}
	}

	// If t is set, print "NO" indicating the number is not lucky
	if t == 1 {
		fmt.Println("NO")
	} else {
		// Calculate the sum of the first half of the digits
		for i := 0; i < n/2; i++ {
			x = x + int(l[i]-'0')
		}
		// Calculate the sum of the second half of the digits
		for i := n - 1; i > (n/2)-1; i-- {
			y = y + int(l[i]-'0')
		}
		// Compare the two sums and print "YES" if they are equal, otherwise print "NO"
		if x == y {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

