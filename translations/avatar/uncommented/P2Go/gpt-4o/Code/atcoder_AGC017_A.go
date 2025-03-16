package main

import (
	"fmt"
)

func combi(N, K int) int {
	a := 1
	for i := 0; i < K; i++ {
		a *= N - i
	}
	for j := 0; j < K; j++ {
		a /= j + 1
	}
	return a
}

func main() {
	var N, P int
	fmt.Scan(&N, &P)

	lis := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&lis[i])
	}

	ls := make([]int, N)
	for i, a := range lis {
		ls[i] = a % 2
	}

	one := 0
	zero := 0
	for _, val := range ls {
		if val == 1 {
			one++
		} else {
			zero++
		}
	}

	patternA := 0
	patternB := 0
	for j := 0; j <= zero; j++ {
		patternB += combi(zero, j)
	}

	time := 0
	for time <= one {
		if time%2 == P {
			patternA += combi(one, time)
		}
		time++
	}

	fmt.Println(patternA * patternB)
}

// <END-OF-CODE>
