package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new reader to read input from the console
	reader := bufio.NewReader(os.Stdin)
	
	// Read a line of input and split it into an array of strings
	input, _ := reader.ReadString('\n')
	str := strings.Split(strings.TrimSpace(input), " ")
	
	// Parse the first string as an integer representing the initial health
	h, _ := strconv.Atoi(str[0])
	
	// Parse the second string as an integer representing the damage dealt per attack
	a, _ := strconv.Atoi(str[1])
	
	// Initialize a counter to keep track of the number of attacks
	num := 0
	
	// Loop until the health is greater than zero
	for h > 0 {
		// Decrease health by the amount of damage dealt
		h -= a
		
		// Increment the attack counter
		num++
	}
	
	// Output the total number of attacks required to reduce health to zero or below
	fmt.Println(num)
}

