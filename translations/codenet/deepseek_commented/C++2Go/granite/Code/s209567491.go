
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var N, D, X int
	fmt.Fscanf(reader, "%d %d %d\n", &N, &D, &X)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscanf(reader, "%d", &A[i])
	}

	numOfChocolate := 0
	for i := 0; i < N; i++ {
		days := 0
		counter := 0
		for j := 0; ; j++ {
			days = j*A[i] + 1
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

