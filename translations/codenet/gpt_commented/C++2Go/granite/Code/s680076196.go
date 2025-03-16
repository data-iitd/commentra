
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var a, b, c, d int
	var err error

	// Read four integer values from standard input
	a, err = strconv.Atoi(readLine(reader))
	checkError(err)
	b, err = strconv.Atoi(readLine(reader))
	checkError(err)
	c, err = strconv.Atoi(readLine(reader))
	checkError(err)
	d, err = strconv.Atoi(readLine(reader))
	checkError(err)

	// Calculate the product of the differences between the first two and the last two integers
	// This represents the area of a rectangle defined by the points (a, b) and (c, d)
	area := (a - c) * (b - d)

	// Print the calculated area to standard output
	fmt.Println(area)
}

func readLine(reader *bufio.Reader) string {
	line, _, err := reader.ReadLine()
	if err!= nil {
		panic(err)
	}
	return string(line)
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

