
package main

import (
    "fmt"
    "math"
)

var debug bool

func log(text string) {
    if debug {
        fmt.Println(text)
    }
}

// Function to parse input from either user input or a string
func parseInput(linesAsString string) (string,) {
    var lines []string
    if linesAsString == "" {
        debug = false
        lines = append(lines, input())
    } else {
        debug = true
        lines = [e for e in linesAsString.split("\n")][1:-1]
    }
    c := [e for e in lines[0].split(" ")] [0]
    return c,
}

// Function to solve the problem by finding the next character in the alphabet
func solve(c string) string {
    a := "abcdefghijklmnopqrstuvwxyz"
    i := a.index(c)
    return a[i+1]
}

// Main function to orchestrate the execution of the program
func main() {
    result := solve(*parseInput())
    if isinstance(result, list) {
        for r in result {
            fmt.Printf("%s", r, sep = '')
        }
    } else {
        fmt.Printf("%s", result, sep = '')
    }
}

// 