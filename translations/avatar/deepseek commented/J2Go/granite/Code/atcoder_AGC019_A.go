
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Reading input values
	Q, _ := strconv.ParseInt(readLine(reader), 10, 64)
	H, _ := strconv.ParseInt(readLine(reader), 10, 64)
	S, _ := strconv.ParseInt(readLine(reader), 10, 64)
	D, _ := strconv.ParseInt(readLine(reader), 10, 64)
	N, _ := strconv.ParseInt(readLine(reader), 10, 64)

	// Calculating the minimum price for one unit
	onePrice := int(Min(Min(Q*4, H*2), S))

	// Conditional logic to determine the total cost
	if float64(onePrice) <= float64(D)/2 {
		fmt.Println(N * onePrice)
	} else {
		fmt.Println((N/2)*D + (N%2)*onePrice)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}

	return ""
}

func Min(x, y int64) int64 {
	if x < y {
		return x
	}

	return y
}

