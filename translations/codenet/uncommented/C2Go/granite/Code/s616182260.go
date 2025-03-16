
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	c := make([][]int, 3)
	for i := 0; i < 3; i++ {
		c[i] = make([]int, 3)
	}
	a := make([]int, 3)
	b := make([]int, 3)
	for i := 0; i < 3; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d%d%d", &c[i][0], &c[i][1], &c[i][2])
	}
	a[0] = 0
	for i := 0; i < 3; i++ {
		b[i] = c[0][i]
	}
	for i := 1; i < 3; i++ {
		a[i] = c[i][0] - b[0]
	}
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if c[i][j]!= a[i]+b[j] {
				fmt.Println("No")
				return
			}
		}
	}
	fmt.Println("Yes")
}

