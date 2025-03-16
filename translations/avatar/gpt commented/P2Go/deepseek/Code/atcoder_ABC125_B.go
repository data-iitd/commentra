package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements
	N, _ := strconv.Atoi(readLine(reader))

	// Read the values into a list and convert them to integers
	V := readLine(reader)
	V = strings.Split(V, " ")
	VInt := make([]int, N)
	for i := 0; i < N; i++ {
		VInt[i], _ = strconv.Atoi(V[i])
	}

	// Read the costs into a list and convert them to integers
	C := readLine(reader)
	C = strings.Split(C, " ")
	CInt := make([]int, N)
	for i := 0; i < N; i++ {
		CInt[i], _ = strconv.Atoi(C[i])
	}

	// Initialize a list to store the profit differences, starting with 0
	profit_differences := []int{0}

	// Initialize a variable to hold the total profit
	ans := 0

	// Initialize variables to hold current value and cost
	var X, Y int

	// Iterate through each item
	for i := 0; i < N; i++ {
		// Check if the value is greater than the cost
		if VInt[i] - CInt[i] > 0 {
			// Assign the current value and cost to X and Y
			X = VInt[i]
			Y = CInt[i]
			// Calculate the profit and append it to the profit differences list
			profit_differences = append(profit_differences, X - Y)
		}
	}

	// Calculate and print the total profit by summing the profit differences
	for _, profit := range profit_differences {
		ans += profit
	}
	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return strings.TrimRight(string(str), "\r\n")
}
