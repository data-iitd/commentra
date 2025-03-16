package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a BufferedReader to read input from the console
	reader := bufio.NewReader(os.Stdin)
	
	// Read a line of input and split it into an array of strings
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	list := strings.Split(line, " ")
	
	// Parse the first three elements of the input into integers
	x, _ := strconv.Atoi(list[0])
	a, _ := strconv.Atoi(list[1])
	y, _ := strconv.Atoi(list[2])
	
	// Initialize a variable to hold the result, defaulting to "NO"
	h := "NO"
	
	// Check if any of the numbers x, a, or y are either 5 or 7
	if x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7 {
		// If the sum of x, a, and y equals 17, set the result to "YES"
		if x + y + a == 17 {
			h = "YES"
		}
	}
	
	// Output the result
	fmt.Println(h)
}
