
package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, err := strconv.ParseFloat(readLine(reader), 64)
	if err!= nil {
		panic(err)
	}
	countOdd := math.Round(input / 2)
	result := countOdd / input
	fmt.Printf("%.10f\n", result)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return string(str)
}

