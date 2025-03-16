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
	var arr []byte
	var N int
	var K int
	var res int
	var a int
	var b int
	var input string
	arr = []byte(strings.TrimSpace(reader.ReadString()))
	N = len(arr)
	K, _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	for k := 0; k < K; k++ {
		input = strings.TrimSpace(reader.ReadString())
		a = 0
		b = 0
		for i := 0; i < N; i++ {
			if arr[i] == input[0] {
				a++
			} else if arr[i] == input[1] {
				b++
			} else {
				res += min(a, b)
				a = b = 0
			}
		}
		res += min(a, b)
	}
	fmt.Println(res)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

