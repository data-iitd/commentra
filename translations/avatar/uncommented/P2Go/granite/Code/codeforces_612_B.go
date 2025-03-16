
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
	n, _ := strconv.Atoi(readerReadLine(reader))
	a := readLine(reader)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		b[i], _ = strconv.Atoi(a[i])
	}
	res := 0
	for i := 1; i < n; i++ {
		res += abs(b[i]-b[i-1])
	}
	fmt.Println(res)
}

func readerReadLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	} else {
		panic(err)
	}
}

func readLine(reader *bufio.Reader) []string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Split(string(str), " ")
	} else {
		panic(err)
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
