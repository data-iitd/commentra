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
	input, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(input))

	input, _ = reader.ReadString('\n')
	A := []int{}
	for _, numStr := range strings.Split(strings.TrimSpace(input), " ") {
		num, _ := strconv.Atoi(numStr)
		A = append(A, num)
	}

	mn, mx := N+1, -1

	for i := 0; i < N; i++ {
		if (i+1 != A[i]) {
			if mn > i {
				mn = i
			}
			if mx < i {
				mx = i
			}
		}
	}

	if mx == -1 {
		fmt.Println("0 0")
	} else {
		A = append(A[:mn], append(A[mn:mx+1][::-1], A[mx+1:]...)...)
		sortedA := make([]int, len(A))
		copy(sortedA, A)
		sort.Ints(sortedA)
		if reflect.DeepEqual(A, sortedA) {
			fmt.Println(mn+1, mx+1)
		} else {
			fmt.Println("0 0")
		}
	}
}
