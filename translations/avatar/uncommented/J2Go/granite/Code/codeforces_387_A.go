
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"time"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s := strings.Split(strings.TrimSpace(readLine(reader)), ":")
	t := strings.Split(strings.TrimSpace(readLine(reader)), ":")
	x := time.Date(1, 1, 1, int(s[0]), int(s[1]), 0, 0, time.UTC)
	y := time.Date(1, 1, 1, int(t[0]), int(t[1]), 0, 0, time.UTC)
	fmt.Println(x.Sub(y))
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}

	return ""
}

