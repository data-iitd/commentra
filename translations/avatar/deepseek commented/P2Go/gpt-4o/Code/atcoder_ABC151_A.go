package main

import (
	"fmt"
	"strings"
)

var debug = false

func log(text string) {
	if debug {
		fmt.Println(text)
	}
}

// Function to parse input from either user input or a string
func parseInput(linesAsString string) (string, error) {
	var lines []string
	if linesAsString == "" {
		debug = false
		var input string
		fmt.Scanln(&input)
		lines = append(lines, input)
	} else {
		debug = true
		lines = strings.Split(linesAsString, "\n")[1 : len(strings.Split(linesAsString, "\n"))-1]
	}
	c := strings.Fields(lines[0])[0]
	return c, nil
}

// Function to solve the problem by finding the next character in the alphabet
func solve(c string) string {
	a := "abcdefghijklmnopqrstuvwxyz"
	i := strings.Index(a, c)
	return string(a[i+1])
}

// Main function to orchestrate the execution of the program
func main() {
	c, err := parseInput("")
	if err != nil {
		fmt.Println("Error parsing input:", err)
		return
	}
	result := solve(c)
	fmt.Printf("%s\n", result)
}

// <END-OF-CODE>
