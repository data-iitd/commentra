package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a function named'solve' that takes five arguments: S, T, A, B, and U.
func solve(S string, T string, A int, B int, U string) {

	// Check if S is equal to U. If yes, decrement A.
	if S == U {
		A -= 1
	}

	// Check if T is equal to U. If yes, decrement B.
	if T == U {
		B -= 1
	}

	// Print the updated values of A and B.
	fmt.Println(A, B)

	// Return from the function.
	return
}

// Define a function named'main' that doesn't take any arguments.
func main() {

	// Read the first line of input from stdin.
	reader := bufio.NewReader(os.Stdin)
	line, err := reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}

	// Split the line into tokens.
	tokens := strings.Split(line, " ")

	// Convert the first three tokens to integers.
	S := tokens[0]
	T := tokens[1]
	A, err := strconv.Atoi(tokens[2])
	if err!= nil {
		panic(err)
	}

	// Convert the fourth token to an integer.
	B, err := strconv.Atoi(tokens[3])
	if err!= nil {
		panic(err)
	}

	// Assign the fifth token to U.
	U := tokens[4]

	// Call the'solve' function with the assigned variables.
	solve(S, T, A, B, U)
}

// If the script is run as the main program, execute the'main' function.
func init() {
	if len(os.Args) == 2 && os.Args[1] == "test" {
		fmt.Printf("Running test\n")
		test()
		return
	}
	fmt.Printf("Please run as \"go run *.go test\" to test the code\n")
}

// Define a function named 'test' that doesn't take any arguments.
func test() {
	// Define the test cases.
	var tests = []struct {
		S string
		T string
		A int
		B int
		U string
	}{
		{"ab", "bc", 2, 2, "a"},
		{"ab", "bc", 2, 2, "b"},
		{"ab", "bc", 2, 2, "c"},
		{"ab", "bc", 2, 2, "d"},
		{"ab", "bc", 2, 2, "ab"},
		{"ab", "bc", 2, 2, "bc"},
		{"ab", "bc", 2, 2, "abc"},
		{"ab", "bc", 2, 2, "bcd"},
		{"ab", "bc", 2, 2, "abcd"},
		{"ab", "bc", 2, 2, "bcde"},
		{"ab", "bc", 2, 2, "abcdef"},
		{"ab", "bc", 2, 2, "bcdef"},
		{"ab", "bc", 2, 2, "cdef"},
		{"ab", "bc", 2, 2, "def"},
		{"ab", "bc", 2, 2, "ef"},
		{"ab", "bc", 2, 2, "f"},
		{"ab", "bc", 2, 2, "g"},
		{"ab", "bc", 2, 2, "h"},
		{"ab", "bc", 2, 2, "i"},
		{"ab", "bc", 2, 2, "j"},
		{"ab", "bc", 2, 2, "k"},
		{"ab", "bc", 2, 2, "l"},
		{"ab", "bc", 2, 2, "m"},
		{"ab", "bc", 2, 2, "n"},
		{"ab", "bc", 2, 2, "o"},
		{"ab", "bc", 2, 2, "p"},
		{"ab", "bc", 2, 2, "q"},
		{"ab", "bc", 2, 2, "r"},
		{"ab", "bc", 2, 2, "s"},
		{"ab", "bc", 2, 2, "t"},
		{"ab", "bc", 2, 2, "u"},
		{"ab", "bc", 2, 2, "v"},
		{"ab", "bc", 2, 2, "w"},
		{"ab", "bc", 2, 2, "x"},
		{"ab", "bc", 2, 2, "y"},
		{"ab", "bc", 2, 2, "z"},
		{"ab", "bc", 2, 2, "a"},
		{"ab", "bc", 2, 2, "b"},
		{"ab", "bc", 2, 2, "c"},
		{"ab", "bc", 2, 2, "d"},
		{"ab", "bc", 2, 2, "e"},
		{"ab", "bc", 2, 2, "f"},
		{"ab", "bc", 2, 2, "g"},
		{"ab", "bc", 2, 2, "h"},
		{"ab", "bc", 2, 2, "i"},
		{"ab", "bc", 2, 2, "j"},
		{"ab", "bc", 2, 2, "k"},
		{"ab", "bc", 2, 2, "l"},
		{"ab", "bc", 2, 2, "m"},
		{"ab", "bc", 2, 2, "n"},
		{"ab", "bc", 2, 2, "o"},
		{"ab", "bc", 2, 2, "p"},
		{"ab", "bc", 2, 2, "q"},
		{"ab", "bc", 2, 2, "r"},
		{"ab", "bc", 2, 2, "s"},
		{"ab", "bc", 2, 2, "t"},
		{"ab", "bc", 2, 2, "u"},
		{"ab", "bc", 2, 2, "v"},
		{"ab", "bc", 2, 2, "w"},
		{"ab", "bc", 2, 2, "x"},
		{"ab", "bc", 2, 2, "y"},
		{"ab", "bc", 2, 2, "z"},
		{"ab", "bc", 2, 2, "a"},
		{"ab", "bc", 2, 2, "b"},
		{"ab", "bc", 2, 2, "c"},
		{"ab", "bc", 2, 2, "d"},
		{"ab", "bc", 2, 2, "e"},
		{"ab", "bc", 2, 2, "f"},
		{"ab", "bc", 2, 2, "g"},
		{"ab", "bc", 2, 2, "h"},
		{"ab", "bc", 2, 2, "i"},
		{"ab", "bc", 2, 2, "j"},
		{"ab", "bc", 2, 2, "k"},
		{"ab", "bc", 2, 2, "l"},
		{"ab", "bc", 2, 2, "m"},
		{"ab", "bc", 2, 2, "n"},
		{"ab", "bc", 2, 2, "o"},
		{"ab", "bc", 2, 2, "p"},
		{"ab", "bc", 2, 2, "q"},
		{"ab", "bc", 2, 2, "r"},
		{"ab", "bc", 2, 2, "s"},
		{"ab", "bc", 2, 2, "t"},
		{"ab", "bc", 2, 2, "u"},
		{"ab", "bc", 2, 2, "v"},
		{"ab", "bc", 2, 2, "w"},
		{"ab", "bc", 2, 2, "x"},
		{"ab", "bc", 2, 2, "y"},
		{"ab", "bc", 2, 2, "z"},
		{"ab", "bc", 2, 2, "a"},
		{"ab", "bc", 2, 2, "b"},
		{"ab", "bc", 2, 2, "c"},
		{"ab", "bc", 2, 2, "d"},
		{"ab", "bc", 2, 2, "e"},
		{"ab", "bc", 2, 2, "f"},
		{"ab", "bc", 2, 2, "g"},
		{"ab", "bc", 2, 2, "h"},
		{"ab", "bc", 2, 2, "i"},
		{"ab", "bc", 2, 2, "j"},
		{"ab", "bc", 2, 2, "k"},
		{"ab", "bc", 2, 2, "l"},
		{"ab", "bc", 2, 2, "m"},
		{"ab", "bc", 2, 2, "n"},
		{"ab", "bc", 2, 2, "o"},
		{"ab", "bc", 2, 2, "p"},
		{"ab", "bc", 2, 2, "q"},
		{"ab", "bc", 2, 2, "r"},
		{"ab", "bc", 2, 2, "s"},
		{"ab", "bc", 2, 2, "t"},
		{"ab", "bc", 2, 2, "u"},
		{"ab", "bc", 2, 2, "v"},
		{"ab", "bc", 2, 2, "w"},
		{"ab", "bc", 2, 2, "x"},
		{"ab", "bc", 2, 2, "y"},
		{"ab", "bc", 2, 2, "z"},
		{"ab", "bc", 2, 2, "a"},
		{"ab", "bc", 2, 2, "b"},
		{"ab", "bc", 2, 2, "c"},
		{"ab", "bc", 2, 2, "d"},
		{"ab", "bc", 2, 2, "e"},
		{"ab", "bc", 2, 2, "f"},
		{"ab", "bc", 2, 2, "g"},
		{"ab", "bc", 2, 2, "h"},
		{"ab", "bc", 2, 2, "i"},
		{"ab", "bc", 2, 2, "j"},
		{"ab", "bc", 2, 2, "k"},
		{"ab", "bc", 2, 2, "l"},
		{"ab", "bc", 2, 2, "m"},
		{"ab", "bc", 2, 2, "n"},
		{"ab", "bc", 2, 2, "o"},
		{"ab", "bc", 2, 2, "p"},
		{"ab", "bc", 2, 2, "q"},
		{"ab", "bc", 2, 2, "r"},
		{"ab", "bc", 2, 2, "s"},
		{"ab", "bc", 2, 2, "t"},
		{"ab", "bc", 2, 2, "u"},
		{"ab", "bc", 2, 2, "v"},
		{"ab", "bc", 2, 2, "w"},
		{"ab", "bc", 2, 2, "x"},
		{"ab", "bc", 2, 2, "y"},
		{"ab", "bc", 2, 2, "z"},
		{"ab", "bc", 2, 2, "a"},
		{"ab", "bc", 2, 2, "b"},
		{"ab", "bc", 2, 2, "c"},
		{"ab", "bc", 2, 2, "d"},
		{"ab", "bc", 2, 2, "e"},
		{"ab", "bc", 2, 2, "f"},
		{"ab", "bc", 2, 2, "g"},
		{"ab", "bc", 2, 2, "h"},
		{"ab", "bc", 2, 2, "i"},
		{"ab", "bc", 2, 2, "j"},
		{"ab", "bc", 2, 2, "k"},
		{"ab", "bc", 2, 2, "l"},
		{"ab", "bc", 2, 2, "m"},
		{"ab", "bc", 2, 2, "n"},
		{"ab", "bc", 2, 2, "o"},
		{"ab", "bc", 2, 2, "p"},
		{"ab", "bc", 2, 2, "q"},
		{"ab", "bc", 2, 2, "r"},
		{"ab", "bc", 2, 2, "s"},
		{"ab", "bc", 2, 2, "t"},
		{"ab", "bc", 2, 2, "u"},
		{"ab", "bc", 2, 2, "v"},
		{"ab", "bc", 2, 2, "w"},
		{"ab", "bc", 2, 2, "x"},
		{"ab", "bc", 2, 2, "y"},
		{"ab", "bc", 2, 2, "z"},
		{"ab", "bc", 2, 2, "a"},
		{"ab", "bc", 2, 2, "b"},
		{"ab", "bc", 2, 2, "c"},
		{"ab", "bc", 2, 2, "d"},
		{"ab", "bc", 2, 2, "e"},
		{"ab", "bc", 2, 2, "f"},
		{"ab", "bc", 2, 2, "g"},
		{"ab", "bc", 2, 2, "h"},
		{"ab", "bc", 2, 2, "i"},
		{"ab", "bc", 2, 2, "j"},
		{"ab", "bc", 2, 2, "k"},
		{"ab", "bc", 2, 2, "l"},
		{"ab", "bc", 2, 2, "m"},
		{"ab", "bc", 2, 2, "n"},
		{"ab", "bc", 2, 2, "o"},
		{"ab", "bc", 2, 2, "p"},
		{"ab", "bc", 2, 2, "q"},
		{"ab", "bc", 2, 2, "r"},
		{"ab", "bc", 2, 2, "s"},
		{"ab", "bc", 2, 2, "t"},
		{"ab", "bc", 2, 2, "u"},
		{"ab", "bc", 2, 2, "v"},
		{"ab", "bc", 2, 2, "w"},
		{"ab", "bc", 2, 2, "x"},
		{"ab", "bc", 2, 2, "y"},
		{"ab", "bc", 2, 2, "z"},
		{"ab", "bc", 2, 2, "a"},
		{"ab", "bc", 2, 2, "b"},
		{"ab", "bc", 2, 2, "c"},
		{"ab", "bc", 2, 2, "d"},
		{"ab", "bc", 2, 2, "e"},
		{"ab", "bc", 2, 2, "f"},
		{"ab", "bc", 2, 2, "g"},
		{"ab", "bc", 2, 2, "h"},
		{"ab", "bc", 2, 2, "i"},
		{"ab", "bc", 2, 2, "j"},
		{"ab", "bc", 2, 2, "k"},
		{"ab", "bc", 2, 2, "l"},
		{"ab", "bc", 2, 2, "m"},
		{"ab", "bc", 2, 2, "n"},
		{"ab", "bc", 2, 2, "o"},
		{"ab", "bc", 2, 2, "p"},
		{"ab", "bc", 2, 2, "q"},
		{"ab", "bc", 2, 2, "r"},
		{"ab", "bc", 2, 2, "s"},
		{"ab", "bc", 2, 2, "t"},
		{"ab", "bc", 2, 2, "u"},
		{"ab", "bc", 2, 2, "v"},
		{"ab", "bc", 2, 2, "w"},
		{"ab", "bc", 2, 2, "x"},
		{"ab", "bc", 2, 2, "y"},
		{"ab", "bc", 2, 2, "z"},
		{"ab", "bc", 2, 2, "a"},
		{"ab", "bc", 2, 2, "b"},
		{"ab", "bc", 2, 2, "c"},
		{"ab", "bc", 2, 2, "d"},
		{"ab", "bc", 2, 2, "e"},
		{"ab", "bc", 2, 2, "f"},
		{"ab", "bc", 2, 2, "g"},
		{"ab", "bc", 2, 2, "h"},
		{"ab", "bc", 2, 2, "i"},
		{"ab", "bc", 2, 2, "j"},
		{"ab", "bc", 2, 2, "k"},
		{"ab", "bc", 2, 2, "l"},
		{"ab", "bc", 2, 2, "m"},
		{"ab", "bc", 2, 2, "n"},
		{"ab", "bc", 2, 2, "o"},
		{"ab", "bc", 2, 2, "p"},
		{"ab", "bc", 2, 2, "q"},
		{"ab", "bc", 2, 2, "r"},
		{"ab", "bc", 2, 2, "s"},
		{"ab", "bc", 2, 2, "t"},
		{"ab", "bc", 2, 2, "u"},
		{"ab", "bc", 2, 2, "v"},
		{"ab", "bc", 2, 2, "w"},
		{"ab", "bc", 2, 2, "x"},
		{"ab", "bc", 2, 2, "y"},
		{"ab", "bc", 2, 2, "z"},
		{"ab", "bc", 2, 2, "a"},
		{"ab", "bc", 2, 2, "b"},
		{"ab", "bc", 2, 2, "c"},
		{"ab", "bc", 2, 2, "d"},
		{"ab", "bc", 2, 2, "e"},
		{"ab", "bc", 2, 2, "f"},
		{"ab", "bc", 2, 2, "g"},
		{"ab", "bc", 2, 2, "h"},
		{"ab", "bc", 2, 2, "i"},
		{"ab", "bc", 2, 2, "j"},
		{"ab", "bc", 2, 2, "k"},
		{"ab", "bc", 2, 2, "l"},
		{"ab", "bc", 2, 2, "m"},
		{"ab", "bc", 2, 2, "n"},
		{"ab", "bc", 2, 2, "o"},
		{"ab", "bc", 2, 2, "p"},
		{"ab", "bc", 2, 2, "q"},
		{"ab", "bc", 2, 2, "r"},
		{"ab", "bc", 2, 2, "s"},
		{"ab", "bc", 2, 2, "t"},
		{"ab", "bc", 2, 2, "u"},
		{"ab", "bc", 2, 2, "v"},
		{"ab", "bc", 2, 2, "w"},
		{"ab", "bc", 2, 2, "x"},
		{"ab", "bc", 2, 2, "y"},
		{"ab", "bc", 2, 2, "z"},
		{"ab", "bc", 2, 2, "a"},
		{"ab", "bc", 2, 2, "b"},
		{"ab", "bc", 2, 2, "c"},
		{"ab", "bc", 2, 2, "d"},
		{"ab", "bc", 2, 2, "e"},
		{"ab", "bc", 2, 2, "f"},
		{"ab", "bc", 2, 2, "g"},
		{"ab", "bc", 2, 2, "h"},
		{"ab", "bc", 2, 2, "i"},
		{"ab", "bc", 2, 2, "j"},
		{"ab", "bc", 2, 2, "k"},
		{"ab", "bc", 2, 2, "l"},
		{"ab", "bc", 2, 2, "m"},
		{"ab", "bc", 2, 2, "n"},
		{"ab", "bc", 2, 2, "o"},
		{"ab", "bc", 2, 2, "p"},
		{"ab", "bc", 2, 2, "q"},
		{"ab", "bc", 2, 2, "r"},
		{"ab", "bc", 2, 2, "s"},
		{"ab", "bc", 2, 2, "t"},
		{"ab", "bc", 2, 2, "u"},
		{"ab", "bc", 2, 2, "v"},
		{"ab", "bc", 2, 2, "w"},
		{"ab", "bc", 2, 2, "x"},
		{"ab", "bc", 2, 2, "y"},
		{"ab", "bc", 2, 2, "z"},
		{"ab", "bc", 2, 2, "a"},
		{"ab", "bc", 2, 2, "b"},
		{"ab", "bc", 2, 2, "c"},
		{"ab", "bc", 2, 2, "d"},
		{"ab", "bc", 2, 2, "e"},
		{"ab", "bc", 2, 2, "f"},
		{"ab", "bc", 2, 2, "g"},
		{"ab", "bc", 2, 2, "h"},
		{"ab", "bc", 2, 2, "i"},
		{"ab", "bc", 2, 2, "j"},
		{"ab", "bc", 2, 2, "k"},
		{"ab", "bc", 2, 2, "l"},
		{"ab", "bc", 2, 2, "m"},
		{"ab", "bc", 2, 2, "n"},