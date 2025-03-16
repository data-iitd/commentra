package main

import (
	"fmt"
	"os"
	"strings"
)

var debug = false

func log(text string) {
	if debug {
		fmt.Println(text)
	}
}

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

func solve(c string) string {
	a := "abcdefghijklmnopqrstuvwxyz"
	i := strings.Index(a, c)
	return string(a[i+1])
}

func main() {
	result, err := parseInput("")
	if err != nil {
		fmt.Println("Error parsing input:", err)
		os.Exit(1)
	}
	output := solve(result)
	fmt.Println(output)
}

// <END-OF-CODE>
