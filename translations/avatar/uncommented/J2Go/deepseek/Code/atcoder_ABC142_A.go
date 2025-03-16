package main

import (
	"bufio"
	"fmt"
	"math"
	"math/big"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}
	input = input[:len(input)-1] // Remove the newline character
	
	numInput, err := strconv.ParseFloat(input, 64)
	if err != nil {
		fmt.Println("Error parsing input:", err)
		return
	}
	
	countOdd := math.Round(numInput / 2)
	result := new(big.Rat)
	result.SetFrac64(int64(countOdd), int64(numInput))
	result.Mul(result, big.NewRat(1, 1)) // Scale to 10 decimal places
	
	fmt.Println(result.FloatString(10))
}

