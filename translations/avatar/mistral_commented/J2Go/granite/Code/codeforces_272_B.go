

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
	writer := bufio.NewWriter(os.Stdout)

	n, _ := strconv.Atoi(readerReadLine(reader))

	a := make([]int, 33)

	for i := 0; i < n; i++ {
		num, _ := strconv.Atoi(readerReadLine(reader))
		index := rec(num)
		a[index]++
	}

	answer := 0.0

	for i := 0; i < len(a); i++ {
		summ := (1 + a[i] - 1) / 2.0 * (a[i] - 1)
		answer += summ
	}

	fmt.Println(int64(answer))

	_ = writer.Flush()
}

func readerReadLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), " \r\n")
	}
	panic(err)
}

func rec(x int) int {
	answer := 0

	for k := 31; k >= 0; k-- {
		if x&(1<<k)!= 0 {
			answer++
		}
	}

	return answer
}

These comments should provide a clear understanding of the code for anyone who reads it.