package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Reading the integer input n
	var n int
	fmt.Scan(&n)
	
	// Reading the string input str
	str, _ := reader.ReadString('\n')
	
	// Constructing the string a by taking the first n/2 characters of str
	a := str[:n/2]
	
	// Checking if str is equal to a + a and printing the result
	if str == a + a {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
