
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	N, D, X := readInt()
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i] = readInt()
	}
	numOfChocolate := 0
	for i := 0; i < N; i++ {
		days := 0
		counter := 0
		for j := 0; ; j++ {
			days = j * A[i] + 1
			if days <= D {
				counter++
			} else {
				break
			}
		}
		numOfChocolate += counter
	}
	numOfChocolate += X
	fmt.Println(numOfChocolate)
}

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

