

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	N, _ := strconv.Atoi(read(reader))

	var nx, ny, nt, t, x, y int

	for i := 0; i < N; i++ {
		t, _ = strconv.Atoi(read(reader))
		x, _ = strconv.Atoi(read(reader))
		y, _ = strconv.Atoi(read(reader))

		tmp := t - nt - (abs(x-nx)+abs(y-ny))

		if tmp < 0 || tmp%2!= 0 {
			fmt.Println("No")
			return
		}

		nx, ny, nt = x, y, t
	}

	fmt.Println("Yes")
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

