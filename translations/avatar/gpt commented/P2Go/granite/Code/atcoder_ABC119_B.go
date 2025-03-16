
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of currency inputs from the user
	N, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())

	// Create a list of converted currency values
	// For each input, replace 'JPY' with its equivalent in float and 'BTC' with its equivalent in float
	x := make([]float64, N)
	for i := 0; i < N; i++ {
		input := bufio.NewReader(os.Stdin).Scan()
		input = strings.Replace(input, "JPY", "* 1.0", -1)
		input = strings.Replace(input, "BTC", "* 380000.0", -1)
		x[i], _ = strconv.ParseFloat(input, 64)
	}

	// Calculate and print the total sum of the converted currency values
	total := 0.0
	for _, value := range x {
		total += value
	}
	fmt.Println(total)
}
