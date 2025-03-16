package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to calculate the multiplication part of the expression
func mul(str string, idx int) int {
	res := int(str[idx] - '0') // Extract the first digit and store it in 'res'
	for idx+1 < len(str) && str[idx+1] == '*' { // Check if there is a '*' symbol
		idx += 2 // Move the index to the next symbol
		res *= int(str[idx] - '0') // Multiply 'res' with the next digit
	}
	return res // Return the final result
}

// Function to calculate the addition part of the expression
func add(str string, idx int) int {
	res := mul(str, idx) // Call the 'mul' function to calculate the multiplication part
	for idx+1 < len(str) && str[idx+1] == '+' { // Check if there is a '+' symbol
		idx += 2 // Move the index to the next symbol
		res += mul(str, idx) // Add the result of the next multiplication part
	}
	return res // Return the final result
}

// Function to calculate the whole expression
func bob(str string, idx int) int {
	res := int(str[idx] - '0') // Extract the first digit and store it in 'res'
	for idx+1 < len(str) { // Loop through the rest of the expression
		if str[idx+1] == '+' {
			idx += 2 // Move the index to the next symbol
			res += int(str[idx] - '0') // Add the next digit
		} else {
			idx += 2 // Move the index to the next symbol
			res *= int(str[idx] - '0') // Multiply the next digit
		}
	}
	return res // Return the final result
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		parts := strings.Split(line, " ")
		s := parts[0]
		d, _ := strconv.Atoi(parts[1])
		idx := 0
		a := add(s, idx)
		idx = 0
		b := bob(s, idx)
		if a == d {
			if b == d {
				fmt.Println("U")
			} else {
				fmt.Println("M")
			}
		} else {
			if b == d {
				fmt.Println("L")
			} else {
				fmt.Println("I")
			}
		}
	}
}

