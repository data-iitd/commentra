
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
	a, _ := strconv.ParseInt(readLine(reader), 10, 64)
	b := readLine(reader)
	b = strings.Replace(b, ".", "", -1)
	bInt, _ := strconv.ParseInt(b, 10, 64)
	result := (a * bInt) / 100
	fmt.Println(result)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

