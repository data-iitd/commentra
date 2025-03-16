
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
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	a := make([]int, 33)
	for i := 0; i < n; i++ {
		s := strings.Split(reader.ReadLine(), " ")
		a[rec(s[0])]++
	}
	var answer float64
	for i := 0; i < 33; i++ {
		summ := (1 + float64(a[i]) - 1) / 2.0 * (float64(a[i]) - 1)
		answer += summ
	}
	fmt.Println(int64(answer))
}

func rec(x string) int {
	answer := 0
	for _, v := range x {
		if v == '1' {
			answer++
		}
	}
	return answer
}

// 