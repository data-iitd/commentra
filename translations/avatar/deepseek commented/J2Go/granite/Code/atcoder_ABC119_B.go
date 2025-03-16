
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
	NTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	N := int32(NTemp)
	x := make([]float64, N)
	u := make([]string, N)
	for i := int32(0); i < N; i++ {
		xTemp, err := strconv.ParseFloat(readLine(reader), 64)
		checkError(err)
		x[i] = xTemp
		u[i] = readLine(reader)
	}
	result := solve(x, u)
	fmt.Println(result)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

func solve(x []float64, u []string) float64 {
	total := 0.0
	for i := 0; i < len(x); i++ {
		if u[i] == "JPY" {
			total += x[i]
		} else {
			total += x[i] * 380000
		}
	}
	return total
}

// 