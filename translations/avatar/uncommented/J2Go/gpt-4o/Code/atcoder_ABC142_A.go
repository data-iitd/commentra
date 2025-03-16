package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	inputStr, err := reader.ReadString('\n')
	if err != nil {
		fmt.Println(err)
		os.Exit(0)
	}

	var input float64
	_, err = fmt.Sscanf(inputStr, "%f", &input)
	if err != nil {
		fmt.Println(err)
		os.Exit(0)
	}

	countOdd := int(input / 2)
	result := new(big.Float).SetFloat64(float64(countOdd) / input)
	result = result.SetPrec(100).SetMode(big.ToNearestEven) // Set precision and rounding mode

	// Format the result to 10 decimal places
	resultStr := fmt.Sprintf("%.10f", result)
	fmt.Println(resultStr)
}

// <END-OF-CODE>
