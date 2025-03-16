
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
	h, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	w, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	for i := 0; i < h; i++ {
		s := readLine(reader)
		if strings.Contains(s, "snuke") {
			col := string(s[4])
			row := strconv.Itoa(i + 1)
			fmt.Println(col + row)
			return
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimSpace(string(str))
	}
	return ""
}

