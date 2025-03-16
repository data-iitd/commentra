package main

import (
	"fmt"
	"strings"
)

var debug bool

func log(text string) {
	if debug {
		fmt.Println(text)
	}
}

func parseInput(linesAsString []string) (string, []string) {
	debug = false
	if len(linesAsString) == 0 {
		lines := []string{""}
		lines[0] = fmt.Scanln(&lines[0])
	} else {
		debug = true
		lines := linesAsString[1 : len(linesAsString)-1]
	}
	c := strings.Split(lines[0], " ")[0]
	return c, lines
}

func solve(c string) string {
	a := "abcdefghijklmnopqrstuvwxyz"
	i := strings.Index(a, c)
	return string(a[i+1])
}

func main() {
	c, _ := parseInput([]string{""})
	result := solve(c)
	fmt.Println(result)
}

