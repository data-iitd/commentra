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

	// Read the number of currency inputs from the user
	N, _ := strconv.Atoi(readLine(reader))

	// Create a slice to store the converted currency values
	var x []float64

	// Read each input and convert it to float64
	for i := 0; i < N; i++ {
		input := readLine(reader)
		// Replace 'JPY' with its equivalent in float and 'BTC' with its equivalent in float
		converted := strings.Replace(input, "JPY", "* 1.0", -1)
		converted = strings.Replace(converted, "BTC", "* 380000.0", -1)
		value, _ := strconv.ParseFloat(converted, 64)
		x = append(x, value)
	}

	// Calculate and print the total sum of the converted currency values
	total := 0.0
	for _, v := range x {
		total += v
	}
	fmt.Println(total)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return string(str)
}

