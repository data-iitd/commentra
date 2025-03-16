
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
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	k, _ := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
	arr := readNInt64s(reader, n)
	mp := make(map[int64]bool)
	count := 0
	for _, v := range arr {
		if v%k!= 0 {
			count++
			mp[v] = true
		} else if!mp[v/k] {
			count++
			mp[v] = true
		}
	}
	fmt.Println(count)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

func readNInt64s(reader *bufio.Reader, n int) []int64 {
	res := make([]int64, n)
	str, _, err := reader.ReadLine()
	if err == nil {
		for i, num := range strings.Split(strings.TrimSpace(string(str)), " ") {
			val, _ := strconv.ParseInt(num, 10, 64)
			res[i] = val
		}
	}
	return res
}

