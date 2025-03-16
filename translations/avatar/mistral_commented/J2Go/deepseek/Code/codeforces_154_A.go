package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	arr := []rune(readString(reader))
	N := len(arr)

	set := make(map[string]bool)

	K, _ := strconv.Atoi(readString(reader))

	res := 0

	for k := 0; k < K; k++ {
		input := readString(reader)
		a := 0
		b := 0

		for i := 0; i < N; i++ {
			if arr[i] == rune(input[0]) {
				a++
			} else if arr[i] == rune(input[1]) {
				b++
			} else {
				res += min(a, b)
				a = 0
				b = 0
			}
		}

		res += min(a, b)
	}

	fmt.Println(res)
}

func readString(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return str[:len(str)-1]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

