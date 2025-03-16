
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var A, B, C, X int
	var i, j, k, kosu int

	// 整数の入力
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &A)
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &B)
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &C)
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &X)

	X = X / 50

	for i = 0; i <= A; i++ {
		for j = 0; j <= B; j++ {
			for k = 0; k <= C; k++ {
				if X == (10*i)+(2*j)+k {
					kosu++
				}
			}
		}
	}

	fmt.Println(kosu)
}

// 