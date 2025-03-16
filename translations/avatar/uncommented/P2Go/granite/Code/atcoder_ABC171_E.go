
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
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(readerReadLine(reader))
	}
	total := reduce(xor, a, 0)
	fmt.Println(strings.Join(toStrings(map(int, int, func(ai int) int {
		return ai ^ total
	})(a)), " "))
}

func readerReadLine(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

func reduce(f func(int, int) int, a []int, init int) int {
	r := init
	for _, v := range a {
		r = f(r, v)
	}
	return r
}

func xor(a, b int) int {
	return a ^ b
}

func toStrings(a []int) []string {
	r := make([]string, len(a))
	for i, v := range a {
		r[i] = strconv.Itoa(v)
	}
	return r
}

func map(f func(int) int, a []int) []int {
	r := make([]int, len(a))
	for i, v := range a {
		r[i] = f(v)
	}
	return r
}

