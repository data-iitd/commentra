package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	arr, _ := reader.ReadString('\n')
	arr = arr[:len(arr)-1] // Remove the newline character
	N := len(arr)

	var K int
	fmt.Fscan(reader, &K)

	res := 0
	for k := 0; k < K; k++ {
		var input string
		fmt.Fscan(reader, &input)

		a, b := 0, 0
		for i := 0; i < N; i++ {
			if arr[i] == input[0] {
				a++
			} else if arr[i] == input[1] {
				b++
			} else {
				res += min(a, b)
				a, b = 0, 0
			}
		}
		res += min(a, b)
	}

	fmt.Println(res)
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
