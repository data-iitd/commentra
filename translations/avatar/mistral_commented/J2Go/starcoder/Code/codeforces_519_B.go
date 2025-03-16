package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Main function is the entry point of the Go application
	// It has a void return type and no parameters

	sc := bufio.NewScanner(os.Stdin)
	// Creating a new Scanner object and initializing it with the standard input stream

	n, _ := strconv.Atoi(sc.Text())
	// Reading the number of test cases (n) from the input using the Text() method of the Scanner class
	// and converting it to an integer using the Atoi() method of the strconv package

	a := 0
	b := 0
	c := 0
	// Declaring and initializing three integer variables a, b, and c with zero values

	for i := 0; i < n; i++ {
		a += sc.Text()
	}
	// Using a for loop to read and sum up the first number in each test case using the Text() method of the Scanner class
	// and adding it to the variable 'a'

	for i := 0; i < n-1; i++ {
		b += sc.Text()
	}
	// Using a for loop to read and sum up the second number in each test case (except the last one) using the Text() method of the Scanner class
	// and adding it to the variable 'b'

	for i := 0; i < n-2; i++ {
		c += sc.Text()
	}
	// Using a for loop to read and sum up the third number in each test case (except the last two) using the Text() method of the Scanner class
	// and adding it to the variable 'c'

	x := a - b
	// Calculating the difference between the sum of the first and second number in each test case and storing it in a variable 'x'

	y := b - c
	// Calculating the difference between the sum of the second and third number in each test case and storing it in a variable 'y'

	fmt.Println(x)
	fmt.Println(y)
	// Printing the values of 'x' and 'y' to the standard output using the Println() method of the fmt package
}

