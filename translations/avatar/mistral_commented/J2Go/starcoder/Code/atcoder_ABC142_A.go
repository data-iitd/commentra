
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err!= nil && err!= io.EOF {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
	input = strings.TrimSuffix(input, "\n")
	input = strings.TrimSuffix(input, "\r")
	input = strings.TrimSuffix(input, "\r\n")
	inputFloat, err := strconv.ParseFloat(input, 64)
	if err!= nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
	countOdd := math.Round(inputFloat / 2)
	result := countOdd / inputFloat
	result = math.Round(result*10000000000) / 10000000000
	fmt.Println(result)
}

