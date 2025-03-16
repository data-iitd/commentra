package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var debug bool

func log(text string) {
	if debug {
		fmt.Println(text)
	}
}

// Function to parse input from either user input or a string
func parseInput(linesAsString string) (string, error) {
	var lines []string
	if linesAsString == "" {
		scanner := bufio.NewScanner(os.Stdin)
		scanner.Scan()
		lines = append(lines, scanner.Text())
	} else {
		debug = true
		lines = strings.Split(linesAsString, "\n")[1 : len(linesAsString)-1]
	}
	c := strings.Split(lines[0], " ")[0]
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
		fmt.Println(err)
		return
	}
	result := solve(c)
	fmt.Println(result)
}

