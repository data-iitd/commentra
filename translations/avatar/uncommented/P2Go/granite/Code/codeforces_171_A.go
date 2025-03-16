
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
	a, b := strings.Split(strings.TrimSpace(readLine(reader)), " ")
	x := int(math.Max(float64(len(a)), float64(len(b))))
	a = strings.Repeat("0", x-len(a)) + a
	b = strings.Repeat("0", x-len(b)) + b
	s := ""
	c := 0
	for i := 0; i < x; i++ {
		d := int(b[i]-'0') + int(a[x-i-1]-'0') + c
		if d > 9 {
			s += string(d%10 + '0')
			c = 1
		} else {
			s += string(d + '0')
			c = 0
		}
	}
	if c == 1 {
		s += "1"
	}
	fmt.Println(s[len(s)-1::-1])
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

