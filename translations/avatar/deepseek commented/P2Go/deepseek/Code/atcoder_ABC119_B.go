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
	N, _ := strconv.Atoi(readLine(reader))
	x := make([]float64, N)

	for i := 0; i < N; i++ {
		input := readLine(reader)
		input = strings.ReplaceAll(input, "JPY", "* 1.0")
		input = strings.ReplaceAll(input, "BTC", "* 380000.0")
		expr, _ := strconv.ParseFloat(input, 64)
		x[i] = expr
	}

	sum := 0.0
	for _, value := range x {
		sum += value
	}

	fmt.Println(sum)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return strings.TrimRight(string(str), "\r\n")
}
