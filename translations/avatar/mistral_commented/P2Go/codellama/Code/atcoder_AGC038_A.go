// Package main is the entry point for the program.
package main

// Import the fmt package for printing formatted strings.
import "fmt"

// Define a function named 'solve' that takes four integer arguments: H, W, A, and B.
func solve(H, W, A, B int) {

	// Initialize a 2D array named 'answer' of size H x W with all elements set to the string "0".
	answer := make([][]string, H)
	for i := range answer {
		answer[i] = make([]string, W)
		for j := range answer[i] {
			answer[i][j] = "0"
		}
	}

	// Iterate through each row 'i' in the range of H.
	for i := 0; i < H; i++ {
		// Iterate through each column 'j' in the range of W.
		for j := 0; j < W; j++ {
			// Set the value of the cell 'answer[i][j]' based on the conditions.
			if i < B {
				if j < A {
					answer[i][j] = "0"
				} else {
					answer[i][j] = "1"
				}
			} else {
				if j < A {
					answer[i][j] = "1"
				} else {
					answer[i][j] = "0"
				}
			}
		}
	}

	// Iterate through each row 'i' in the range of H and print its elements joined by an empty string.
	for i := 0; i < H; i++ {
		fmt.Println(answer[i])
	}
}

// Define a function named 'main' that does not take any arguments.
func main() {

	// Define an inner function named 'iterateTokens' that reads input from standard input and yields each token as a string.
	iterateTokens := func() <-chan string {
		ch := make(chan string)
		go func() {
			for {
				var line string
				fmt.Scanln(&line)
				for _, word := range strings.Fields(line) {
					ch <- word
				}
			}
		}()
		return ch
	}

	// Read the input tokens and assign them to the variables H, W, A, and B.
	tokens := iterateTokens()
	H, _ := strconv.Atoi(<-tokens)
	W, _ := strconv.Atoi(<-tokens)
	A, _ := strconv.Atoi(<-tokens)
	B, _ := strconv.Atoi(<-tokens)

	// Call the 'solve' function with the given input.
	solve(H, W, A, B)
}

// If the script is run as the main program, call the 'main' function.
func init() {
	main()
}

