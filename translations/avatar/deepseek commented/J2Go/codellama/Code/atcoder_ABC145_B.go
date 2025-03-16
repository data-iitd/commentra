
package main

import (
	"fmt"
	"os"
	"bufio"
	"strings"
)

func main() {
	// Reading the integer input n
	var n int
	fmt.Scan(&n)
	fmt.Scanln()

	// Reading the string input str
	var str string
	fmt.Scanln(&str)

	// Constructing the string a by taking the first n/2 characters of str
	var a string
	for i := 0; i < n/2; i++ {
		a = a + string(str[i])
	}

	// Checking if str is equal to a + a and printing the result
	if str == a+a {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

