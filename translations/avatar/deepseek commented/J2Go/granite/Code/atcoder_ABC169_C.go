

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
	a, _ := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
	b := readLine(reader)
	b = strings.TrimSpace(b)
	b = strings.Replace(b, ".", "", -1)
	bInt, _ := strconv.Atoi(b)
	result := (a * int64(bInt)) / 100
	fmt.Println(result)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

