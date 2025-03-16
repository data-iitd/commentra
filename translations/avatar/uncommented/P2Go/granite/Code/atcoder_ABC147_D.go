
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MOD = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readerReadLine(reader))
	a := readerReadSlice(reader)
	result := int64(0)
	for b := 0; b < 60; b++ {
		bs := 0
		for _, v := range a {
			if (v>>uint(b))&1 == 1 {
				bs++
			}
		}
		result = (result + int64(bs)*(int64(n)-int64(bs))*(1<<uint(b))) % MOD
	}
	fmt.Println(result)
}

func readerReadLine(reader *bufio.Reader) string {
	line, _, _ := reader.ReadLine()
	return string(line)
}

func readerReadSlice(reader *bufio.Reader) []int {
	line, _, _ := reader.ReadLine()
	s := string(line)
	s = s[:len(s)-1]
	a := make([]int, 0)
	for _, num := range strings.Split(s, " ") {
		n, _ := strconv.Atoi(num)
		a = append(a, n)
	}
	return a
}

