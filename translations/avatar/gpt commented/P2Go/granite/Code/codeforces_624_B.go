
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	readBuf  [1024]byte
	readIndex int
	readBufLen int
)

func init() {
	readBufLen = 0
	readIndex = 0
}

func readByte() byte {
	if readIndex == readBufLen {
		readBufLen, _ = os.Stdin.Read(readBuf[:])
		readIndex = 0
	}
	byte := readBuf[readIndex]
	readIndex++
	return byte
}

func readInt() int {
	sum := 0
	for byte := readByte(); byte >= '0' && byte <= '9'; byte = readByte() {
		sum = sum*10 + int(byte-'0')
	}
	return sum
}

func main() {
	n := readInt()
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readInt()
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
	pre := 1000000001
	ans := 0
	for _, v := range a {
		ans += max(0, min(pre-1, v))
		pre = max(0, min(pre-1, v))
	}
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

