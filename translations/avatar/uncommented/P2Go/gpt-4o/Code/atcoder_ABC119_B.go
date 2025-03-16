package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)

	var total float64
	for i := 0; i < N; i++ {
		var input string
		fmt.Scan(&input)

		// Replace JPY and BTC with their respective multipliers
		input = strings.ReplaceAll(input, "JPY", "*1.0")
		input = strings.ReplaceAll(input, "BTC", "*380000.0")

		// Evaluate the expression
		result, err := evalExpression(input)
		if err != nil {
			fmt.Println("Error evaluating expression:", err)
			return
		}
		total += result
	}

	fmt.Println(total)
}

func evalExpression(expr string) (float64, error) {
	// Split the expression by '*' and evaluate
	parts := strings.Split(expr, "*")
	if len(parts) != 2 {
		return 0, fmt.Errorf("invalid expression")
	}

	// Convert the second part to a float
	value, err := strconv.ParseFloat(strings.TrimSpace(parts[1]), 64)
	if err != nil {
		return 0, err
	}

	return value, nil
}

// Note: This is a simplified evaluation and assumes the input is always valid.
// In a real-world scenario, you would want to implement a more robust expression parser.
