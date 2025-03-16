package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Declare global arrays to store data and sequences
var data [111111]int // Array to store the frequency of each number
var seq [222222]int  // Array to store sequences of consecutive numbers

// Function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	// Loop to read input values and process them
	for {
		scanner.Scan()
		inputs := strings.Fields(scanner.Text())
		n, _ := strconv.Atoi(inputs[0])
		k, _ := strconv.Atoi(inputs[1])
		if n == 0 && k == 0 {
			break // Break the loop if both n and k are zero
		}

		// Initialize the data and seq arrays to zero
		for i := 0; i < 111111; i++ {
			data[i] = 0
		}
		for i := 0; i < 222222; i++ {
			seq[i] = 0
		}

		// Read k numbers and store their frequencies in data
		for i := 0; i < k; i++ {
			scanner.Scan()
			t, _ := strconv.Atoi(scanner.Text())
			data[t]++
		}

		// Construct the seq array based on the frequencies in data
		p := 0
		for i := 1; i <= n; i++ {
			if data[i] > 0 {
				seq[p]++
			} else {
				p += 2
			}
		}
		p++

		// Calculate the maximum value of ret based on the sequences in seq
		ret := 0
		if data[0] > 0 {
			for i := 0; i < p; i++ {
				ret = max(ret, seq[i]+seq[i+2]+1)
			}
		} else {
			for i := 0; i < p; i++ {
				ret = max(ret, seq[i])
			}
		}

		// Print the result
		fmt.Println(ret)
	}
}
