
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	infile := bufio.NewReader(os.Stdin)
	arr, _ := infile.ReadString('\n')
	N := len(arr)
	set := make(map[string]bool)
	K, _ := strconv.Atoi(infile.Text())
	res := 0
	for k := 0; k < K; k++ {
		input, _ := infile.ReadString('\n')
		a := 0
		b := 0
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

