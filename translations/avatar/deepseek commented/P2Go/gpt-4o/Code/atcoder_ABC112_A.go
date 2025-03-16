package main

import (
	"fmt"
)

func main() {
	var age int
	fmt.Scan(&age) // Taking an integer input for the variable `age`
	if age == 1 {  // Checking if `age` is equal to 1
		fmt.Println("Hello World") // If `age` is 1, it prints "Hello World"
	} else { // If `age` is not 1
		var a, b int
		fmt.Scan(&a) // Taking the first integer input and assigning it to `a`
		fmt.Scan(&b) // Taking the second integer input and assigning it to `b`
		fmt.Println(a + b) // Printing the sum of `a` and `b`
	}
}

// <END-OF-CODE>
