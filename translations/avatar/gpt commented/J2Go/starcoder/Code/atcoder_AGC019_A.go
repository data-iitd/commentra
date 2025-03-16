package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Creating a new Scanner object to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Reading the prices of different quantities of the item
	Q, _ := strconv.ParseInt(readLine(reader), 10, 64)
	H, _ := strconv.ParseInt(readLine(reader), 10, 64)
	S, _ := strconv.ParseInt(readLine(reader), 10, 64)
	D, _ := strconv.ParseInt(readLine(reader), 10, 64)
	N, _ := strconv.ParseInt(readLine(reader), 10, 64)

	// Calculating the minimum price for a single item based on the given prices
	onePrice := int64(math.Min(math.Min(float64(Q*4), float64(H*2)), float64(S)))

	// Checking if the price of one item is less than or equal to half the price of buying in pairs
	if float64(onePrice) <= float64(D)/2 {
		// If true, calculate the total cost for N items at the price of one item
		fmt.Println(N * onePrice)
	} else {
		// If false, calculate the total cost using the pair price and the remaining single item price if N is odd
		fmt.Println((N/2)*D + (N%2)*onePrice)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

