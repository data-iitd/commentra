package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read the first input
	input1, _ := reader.ReadString('\n')
	input1 = strings.TrimSpace(input1)
	
	// Initialize an empty list L to store the results
	L := []string{}
	
	// Initialize the variable r to 1
	r := 1
	
	// Split the first input into a list of strings and iterate over each string
	for _, k := range strings.Split(input1, " ") {
		// Multiply the string '1' by the integer value of the string and append the result to the list L
		for i := 0; i < r; i++ {
			L = append(L, strconv.Itoa(r))
		}
		// Increment r by 1 for the next iteration
		r += 1
	}
	
	// Read the second input
	input2, _ := reader.ReadString('\n')
	input2 = strings.TrimSpace(input2)
	
	// Split the second input into a list of strings and iterate over each string
	for _, j := range strings.Split(input2, " ") {
		// For each string, print the element at the index specified by the integer value of the string minus one from the list L
		index, _ := strconv.Atoi(j)
		fmt.Println(L[index - 1])
	}
}

