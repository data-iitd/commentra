package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Creating a BufferedReader object to read input
	bf := bufio.NewReader(os.Stdin)
	// Reading input and splitting it into an array of strings
	x := strings.Split(strings.TrimSpace(bf.Text()), " ")
	// Converting the first element of the array to an integer
	a, _ := strconv.Atoi(x[0])
	// Converting the second element of the array to an integer
	b, _ := strconv.Atoi(x[1])
	// Performing a mathematical operation to calculate a result
	c := a - b*2
	// Checking if the result is negative and setting it to 0 if true
	if c < 0 {
		c = 0
	}
	// Printing the result to the standard output
	fmt.Println(c)
}

