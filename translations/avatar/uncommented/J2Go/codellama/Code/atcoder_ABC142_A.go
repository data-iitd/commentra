
package main

import (
	"bufio"
	"fmt"
	"math"
	"math/big"
	"os"
)

func main() {
	var input float64
	var countOdd float64
	var result big.Rat

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input, _ = strconv.ParseFloat(scanner.Text(), 64)

	countOdd = math.Round(input / 2)
	result.SetFloat64(countOdd / input)
	result.SetScale(10, big.RoundHalfUp)
	fmt.Println(result)
}

