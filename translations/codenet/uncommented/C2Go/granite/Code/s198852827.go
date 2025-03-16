
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	N := readInt()
	t, x, y := 0, 0, 0
	for i := 0; i < N; i++ {
		tmpT, tmpX, tmpY := readInt(), readInt(), readInt()
		tmp := tmpT - t - (abs(tmpX-x)+abs(tmpY-y))
		if tmp < 0 || tmp%2!= 0 {
			fmt.Println("No")
			return
		}
		t, x, y = tmpT, tmpX, tmpY
	}
	fmt.Println("Yes")
}

func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

