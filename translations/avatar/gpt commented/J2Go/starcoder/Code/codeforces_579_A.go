package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Reading an integer input from the user
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a number: ")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	n, _ := strconv.Atoi(input)

	// Initializing an empty string to store the binary representation
	s := ""

	// Converting the integer n to its binary representation
	for n > 0 {
		x := n % 2
		n /= 2
		s += string(x)
	}

	// Initializing a counter to count the number of '1's in the binary representation
	ans := 0

	// Iterating through the binary string to count '1's
	for i := 0; i < len(s); i++ {
		if s[i] == '1' {
			ans++
		}
	}

	// Printing the total count of '1's in the binary representation
	fmt.Println(ans)
}

