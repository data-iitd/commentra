
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Function to perform multiplication based on the custom operator '*' in the string
func mul(str string, idx *int) int {
    // Initialize result with the first digit
    res, _ := strconv.Atoi(string(str[*idx]))
    // Loop through the string to find '*' operators and perform multiplication
    for ; *idx < len(str) && str[*idx+1] == '*'; *idx += 2 {
        res *= int(str[*idx+2] - '0') // Multiply the result with the next number
    }
    return res // Return the final multiplication result
}

// Function to perform addition based on the custom operator '+' in the string
func add(str string, idx *int) int {
    // Start with the first multiplication result
    res := mul(str, idx)
    // Loop through the string to find '+' operators and perform addition
    for ; *idx < len(str) && str[*idx+1] == '+'; *idx += 2 {
        res += mul(str, idx) // Add the next multiplication result to the total
    }
    return res // Return the final addition result
}

// Function to calculate the result based on Bob's interpretation of the expression
func bob(str string, idx *int) int {
    // Initialize result with the first digit
    res, _ := strconv.Atoi(string(str[*idx]))
    // Loop through the string to evaluate the expression according to Bob's rules
    for ; *idx < len(str); *idx += 2 {
        // Check if the next operator is '+' or '*' and perform the corresponding operation
        if str[*idx+1] == '+' {
            res += int(str[*idx+2] - '0') // Add the next number
        } else {
            res *= int(str[*idx+2] - '0') // Multiply by the next number
        }
    }
    return res // Return the final result according to Bob's interpretation
}

func main() {
    // Read input until end of file
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        s := scanner.Text()
        s = strings.TrimSpace(s)
        if s == "