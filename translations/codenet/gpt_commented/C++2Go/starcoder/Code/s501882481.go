package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to convert a string to string (identity function)
func to_string(s string) string {
	return s
}

// Function to print a new line for debugging purposes
func debug() {
	fmt.Println()
}

// Function to print multiple values for debugging
func debugln(a...interface{}) {
	fmt.Println(a...)
}

// Function to print a new line
func print() {
	fmt.Println()
}

// Function to print multiple values to standard output
func println(a...interface{}) {
	fmt.Println(a...)
}

// Function to handle no input (base case for variadic template)
func get() {}

// Function to read multiple values from standard input
func get(a...interface{}) {
	fmt.Scan(a...)
}

// Function to read values into a vector from standard input
func getv(vec *[]int) {
	for i := 0; i < len(*vec); i++ {
		fmt.Scan(&(*vec)[i])
	}
}

// Main function where the program execution begins
func main() {
	var S string
	fmt.Scanln(&S)
	if S == "Sunny" {
		println("Cloudy")
	} else if S == "Cloudy" {
		println("Rainy")
	} else {
		println("Sunny")
	}
}

