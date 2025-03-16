package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declaring variables to hold input values and a counter
	var pandu, vundu, urdu, c int64

	// Reading three long integer values from user input
	fmt.Print("Enter the first integer: ")
	reader := bufio.NewReader(os.Stdin)
	panduString, _ := reader.ReadString('\n')
	pandu, _ = strconv.ParseInt(strings.TrimSpace(panduString), 10, 64)

	fmt.Print("Enter the second integer: ")
	vunduString, _ := reader.ReadString('\n')
	vundu, _ = strconv.ParseInt(strings.TrimSpace(vunduString), 10, 64)

	fmt.Print("Enter the third integer: ")
	urduString, _ := reader.ReadString('\n')
	urdu, _ = strconv.ParseInt(strings.TrimSpace(urduString), 10, 64)

	// Calculating the cumulative sum of 'pandu' multiplied by each integer from 1 to 'urdu'
	for i := int64(1); i <= urdu; i++ {
		c += i * pandu
	}

	// Checking if the calculated sum 'c' is less than 'vundu'
	if c < vundu {
		fmt.Println("0") // If true, print "0"
	} else {
		// If 'c' is greater than or equal to 'vundu', print the difference
		fmt.Println(c - vundu)
	}
}

