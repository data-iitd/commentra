
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	A, B, C, X := readInt()
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

func readInt() (int, int, int, int) {
	scanner := bufio.NewScanner(os.Stdin)
	var A, B, C, X int
	scanner.Scan()
	A, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	B, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	C, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	X, _ = strconv.Atoi(scanner.Text())
	return A, B, C, X
}
