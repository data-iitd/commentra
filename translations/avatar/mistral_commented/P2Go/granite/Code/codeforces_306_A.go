
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readerReadLine(reader)[0])
	m, _ := strconv.Atoi(readerReadLine(reader)[1])
	q := n / m
	r := n % m
	a := make([]int, m)
	for i := 0; i < m; i++ {
		a[i] = q
	}
	for i := 0; i < r; i++ {
		a[i]++
	}
	for i := 0; i < m; i++ {
		fmt.Printf("%d ", a[i])
	}
	fmt.Println()
}

func readerReadLine(reader *bufio.Reader) []string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Split(string(str), " ")
	} else {
		return nil
	}
}

