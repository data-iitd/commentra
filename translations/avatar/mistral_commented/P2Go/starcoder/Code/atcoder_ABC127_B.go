package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Take three integers as input from the user
	r, D, x := getInput()

	// Iterate through the range of numbers from 2 to 11 (12 is excluded)
	for i := 2; i < 12; i++ {
		// Calculate the expression and print the integer result
		fmt.Println(int(math.Round((math.Pow(r, float64(i-1))) * (x + float64(D)/(1-r)) - float64(D)/(1-r))))
	}
}

// getInput takes three integers as input from the user
func getInput() (r, D, x int) {
	// Take three integers as input from the user
	input := strings.Split(os.Args[1], " ")

	// Convert the input to integers
	r, _ = strconv.Atoi(input[0])
	D, _ = strconv.Atoi(input[1])
	x, _ = strconv.Atoi(input[2])

	return r, D, x
}

