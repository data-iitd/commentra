

package main

import (
"bufio"
"fmt"
"os"
"strconv"
)

func main() {
// Create a new scanner to read from the standard input stream
scanner := bufio.NewScanner(os.Stdin)

// Read a line of text from the standard input stream and convert it into a list of integers
scanner.Scan()
vamshi, z := parseLine(scanner.Text())

// Calculate the number of complete divisions of z into vamshi
// Add 1 to account for the remainder
// Multiply the result by z
fmt.Println((vamshi / z + 1) * z)
}

func parseLine(line string) (int, int) {
// Split the line into a list of strings
parts := strings.Split(line, " ")

// Convert the first string into an integer
vamshi, _ := strconv.Atoi(parts[0])

// Convert the second string into an integer
z, _ := strconv.Atoi(parts[1])

// Return the two integers
return vamshi, z
}

