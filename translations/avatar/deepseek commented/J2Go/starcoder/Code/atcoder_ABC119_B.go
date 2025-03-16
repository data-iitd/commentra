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
	fmt.Println("Enter the number of elements in the array")
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	x := make([]float64, N)
	u := make([]string, N)
	fmt.Println("Enter the values of the array")
	for i := 0; i < N; i++ {
		x[i], _ = strconv.ParseFloat(strings.TrimSpace(readLine(reader)), 64)
		u[i] = strings.TrimSpace(readLine(reader))
	}
	fmt.Println(solve(x, u))
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func solve(x []float64, u []string) float64 {
	return float64(len(x))
}

