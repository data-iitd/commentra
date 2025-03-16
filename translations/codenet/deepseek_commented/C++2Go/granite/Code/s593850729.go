
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var A, B, C, X int
	fmt.Fscanf(reader, "%d %d %d %d\n", &A, &B, &C, &X)

	cnt := 0
	for a := 0; a <= A; a++ {
		for b := 0; b <= B; b++ {
			for c := 0; c <= C; c++ {
				total := 500*a + 100*b + 50*c
				if total == X {
					cnt++
				}
			}
		}
	}
	fmt.Println(cnt)
}

