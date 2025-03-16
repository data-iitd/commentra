

package main

import (
	"bufio"
	"fmt"
	"math"
	"math/big"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err!= nil {
		fmt.Println("Error reading input:", err)
		return
	}
	input = strings.TrimSpace(input)
	countOdd, err := strconv.ParseFloat(input, 64)
	if err!= nil {
		fmt.Println("Error parsing input:", err)
		return
	}
	result := new(big.Float).SetPrec(10)
	result.Quo(big.NewFloat(countOdd/2), big.NewFloat(countOdd))
	fmt.Println(result)
}

