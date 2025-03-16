package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read the integer input N which represents the length of the string
	N, _ := reader.ReadString('\n')
	N = strings.TrimSpace(N)
	n := int(N[0] - '0')
	
	// Read the string input S which consists of characters 'R', 'G', and 'B'
	S, _ := reader.ReadString('\n')
	S = strings.TrimSpace(S)
	
	// Call the calculate function with the inputs n and S
	calculate(n, S)
}

func calculate(n int, s string) {
	// Convert the string into a list of characters for easier manipulation
	arr := strings.Split(s, "")
	
	// Count the occurrences of each color in the string
	rNum := 0
	gNum := 0
	bNum := 0
	for _, char := range arr {
		if char == "R" {
			rNum++
		} else if char == "G" {
			gNum++
		} else if char == "B" {
			bNum++
		}
	}
	
	// Initialize a variable to keep track of the number of valid RGB combinations found
	sum := 0
	
	// Loop through possible steps to form combinations of three characters
	for step := 1; step <= int(math.Ceil(float64(n)/2)); step++ {
		// Loop through the string to form combinations based on the current step
		for i := 0; i <= n-2*step; i++ {
			// Create a substring of three characters at the current indices
			s := arr[i] + arr[i+step] + arr[i+step*2]
			
			// Check if the formed substring is one of the valid RGB permutations
			if s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB" {
				// Increment the count of valid combinations found
				sum++
			}
		}
	}
	
	// Calculate and print the result: total combinations minus the valid RGB combinations found
	fmt.Println(rNum * gNum * bNum - sum)
}
