
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	str := strings.Split(strings.TrimSpace(readLine(in)), " ")
	st := strings.Fields(readLine(in))
	a, _ := strconv.Atoi(st[0])
	b, _ := strconv.Atoi(st[1])
	u := readLine(in)
	if u == str[0] {
		fmt.Println(a-1, b)
	} else {
		fmt.Println(a, b-1)
	}
}

func readLine(in *bufio.Reader) string {
	str, _, err := in.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

