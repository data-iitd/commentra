package main

import (
	"fmt"
	"strconv"
	"strings"
)

func parser() <-chan string {
	ch := make(chan string)
	go func() {
		for {
			var input string
			fmt.Scanln(&input) // Read input line
			data := strings.Fields(input) // Split by spaces
			for _, number := range data {
				if len(number) > 0 {
					ch <- number // Send non-empty strings to the channel
				}
			}
		}
	}()
	return ch
}

func gw(ch <-chan string) string {
	return <-ch // Get the next word from the input parser
}

func gi(ch <-chan string) int {
	data := gw(ch)
	num, _ := strconv.Atoi(data) // Convert the string to an integer
	return num
}

const MOD = 1e9 + 7 // Define a constant for modulo operation

func main() {
	inputParser := parser() // Create an instance of the parser

	N := gi(inputParser) // Read the number of elements N from the input
	K := gi(inputParser) // Read the parameter K from the input
	S := gw(inputParser) // Read the string S from the input

	segCnt := 0 // Initialize a counter for the number of segments
	for i := 0; i < N-1; i++ { // Loop through the string to count segments
		if S[i] != S[i+1] { // Check if the current character is different from the next
			segCnt++ // Increment the segment counter if a change is found
		}
	}

	curHappy := N - 1 - segCnt // Calculate the initial happiness based on the number of segments

	var ans int
	if 2*K >= segCnt { // Check if the number of operations allows for maximum happiness
		ans = N - 1 // If yes, set the answer to the maximum possible happiness
	} else {
		ans = curHappy + 2*K // Otherwise, adjust the happiness based on the number of operations
	}

	fmt.Println(ans) // Print the final happiness value
}

// <END-OF-CODE>
