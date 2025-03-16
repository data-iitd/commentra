package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the number of items (n) from stdin
	fmt.Print("Enter the number of items: ")
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	// Read the values (vStr) from stdin and convert to a list
	fmt.Print("Enter the values: ")
	input, _ = reader.ReadString('\n')
	vStr := strings.Split(strings.TrimSpace(input), " ")
	vList := make(map[int]int)
	for i, v := range vStr {
		vList[i] = int(v)
	}

	// Read the costs (cStr) from stdin and convert to a list
	fmt.Print("Enter the costs: ")
	input, _ = reader.ReadString('\n')
	cStr := strings.Split(strings.TrimSpace(input), " ")
	cList := make(map[int]int)
	for i, c := range cStr {
		cList[i] = int(c)
	}

	// Initialize a variable to keep track of the maximum profit
	max := 0

	// Calculate the profit for each item and sum up the positive profits
	for i := 0; i < n; i++ {
		profit := vList[i] - cList[i]
		// Only add to max if the profit is positive
		if profit > 0 {
			max += profit
		}
	}

	// Output the total maximum profit
	fmt.Println(max)
}

