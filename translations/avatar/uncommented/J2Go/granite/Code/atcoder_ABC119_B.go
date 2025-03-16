
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
	nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	n := int32(nTemp)
	x := make([]float64, n)
	u := make([]string, n)
	for i := int32(0); i < n; i++ {
		xTemp := strings.Split(readLine(reader), " ")
		checkError(err)
		x[i], err = strconv.ParseFloat(xTemp[0], 64)
		checkError(err)
		u[i] = xTemp[1]
	}
	result := solve(x, u)
	fmt.Println(result)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), "\r\n")
	}
	panic(err)
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

func solve(x []float64, u []string) float64 {
	sum := 0.0
	for i := 0; i < len(x); i++ {
		if u[i] == "JPY" {
			sum += x[i]
		} else {
			sum += x[i] * 3800000.0
		}
	}
	return sum
}

// 