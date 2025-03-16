package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var inputMethods = []string{"clipboard", "file", "key"}
var usingMethod = 0 // Index to select the input method
var mod = 1000000007 // Define a modulus value for calculations

func main() {
	var s string
	if usingMethod == 0 { // Clipboard input (simulated)
		s = readClipboard()
	} else if usingMethod == 1 { // File input
		s = readFile()
	} else {
		s = readKeyInput()
	}

	result := calculateMinimumScore(s)
	fmt.Println(result)
}

func readClipboard() string {
	// Simulated clipboard input for demonstration purposes
	return "123456" // Replace with actual clipboard reading logic if needed
}

func readFile() string {
	file, err := os.Open("inputFile.txt")
	if err != nil {
		panic(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	scanner.Scan()
	return scanner.Text()
}

func readKeyInput() string {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter input: ")
	text, _ := reader.ReadString('\n')
	return strings.TrimSpace(text)
}

func calculateMinimumScore(s string) int {
	pmin := 1000 // Initialize minimum score for positive values
	mmin := 0    // Initialize minimum score for negative values
	s = "0" + s  // Prepend '0' to the input string for easier processing

	for i := len(s) - 1; i >= 0; i-- {
		v, _ := strconv.Atoi(string(s[i])) // Convert character to integer
		npmin := min(pmin+10-(v+1), mmin+10-v)
		nmmin := min(pmin+v+1, mmin+v)
		pmin = npmin // Update positive minimum score
		mmin = nmmin // Update negative minimum score
	}

	return min(pmin, mmin) // Return the minimum score between positive and negative
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Note: The clipboard functionality is not implemented in this code.
// You would need to use a library or system call to access the clipboard in Go.

