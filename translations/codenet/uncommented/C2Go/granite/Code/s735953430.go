
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	X, _ := strconv.Atoi(read(reader))
	N, _ := strconv.Atoi(read(reader))

	if N == 0 {
		fmt.Println(X)
		return
	}

	plus := make([]int, 256)
	minus := make([]int, 256)
	for i := 0; i < 256; i++ {
		plus[i] = i
		minus[i] = -1 * i
	}

	for i := 0; i < N; i++ {
		j, _ := strconv.Atoi(read(reader))
		plus[j] = 0
	}

	i_min := 0
	min := 1000
	for i := 255; i >= 0; i-- {
		if plus[i] == 0 && i > 0 {
			continue
		}
		k := X - plus[i]
		if k < 0 {
			k *= -1
		}
		if k <= min {
			min = k
			i_min = i
		}
	}

	fmt.Println(i_min)
}

func read(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err!= nil {
		panic(err)
	}

	return string(str)
}

