
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

	tTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	t := int(tTemp)

	for tItr := 0; tItr < t; tItr++ {
		nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
		checkError(err)
		n := int(nTemp)

		result := solve(n)

		fmt.Println(result)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

func solve(n int) int {
	// Calculate the sum of the first n natural numbers
	s := (1 + n) * n / 2
	// Initialize t to 1
	t := 1
	// Subtract twice the sum of powers of 2 up to n from s
	for t <= n {
		s -= 2 * t
		t *= 2
	}
	return s
}

