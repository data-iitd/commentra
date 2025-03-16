package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Optimize input/output operations
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// Read the input string from the user
	str, _ := in.ReadString('\n')

	// Initialize a variable to hold the sum of digits
	sum := 0

	// Iterate through each character in the string
	for _, x := range str {
		// Convert character to integer and add to sum
		sum += int(x - '0')
	}

	// Check if the sum of digits is divisible by 9
	if sum%9 == 0 {
		// If divisible, print "Yes"
		fmt.Println("Yes")
	} else {
		// If not divisible, print "No"
		fmt.Println("No")
	}
}

