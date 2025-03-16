
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
	x, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	count := 0
	tmp := x
	x = 0
	for x!= 360 {
		x = x + tmp
		if x > 360 {
			x = x - 360
		}
		count++
	}
	fmt.Println(count)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimSpace(string(str))
	}
	return ""
}

