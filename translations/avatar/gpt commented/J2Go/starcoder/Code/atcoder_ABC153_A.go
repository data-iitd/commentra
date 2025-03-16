package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new buffered reader.
	reader := bufio.NewReader(os.Stdin)

	// Read a line of input from stdin.
	input, _ := reader.ReadString('\n')

	// Split the input into an array of strings.
	input = strings.Split(input, " ")

	// Parse the first string as an integer representing the initial health.
	health, _ := strconv.Atoi(input[0])

	// Parse the second string as an integer representing the damage dealt per attack.
	damage, _ := strconv.Atoi(input[1])

	// Initialize a counter to keep track of the number of attacks.
	num := 0

	// Loop until the health is greater than zero.
	for health > 0 {
		// Decrease health by the amount of damage dealt.
		health -= damage

		// Increment the attack counter.
		num++
	}

	// Output the total number of attacks required to reduce health to zero or below.
	fmt.Println(num)
}

