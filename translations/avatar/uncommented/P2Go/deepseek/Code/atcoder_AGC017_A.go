package main

import (
	"fmt"
	"math"
)

func combi(N, K int) float64 {
	a := 1.0
	for i := 0; i < K; i++ {
		a *= float64(N - i)
	}
	for j := 0; j < K; j++ {
		a /= float64(j + 1)
	}
	return a
}

func main() {
	var N, P int
	fmt.Scan(&N, &P)

	var lis []int
	var a int
	for {
		_, err := fmt.Scan(&a)
		if err != nil {
			break
		}
		lis = append(lis, a)
	}

	ls := make([]int, len(lis))
	for i, a := range lis {
		ls[i] = a % 2
	}

	one := 0
	zero := 0
	for _, a := range ls {
		if a == 1 {
			one++
		} else {
			zero++
		}
	}

	patternA := 0.0
	patternB := 0.0
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

	fmt.Println(int(patternA * patternB))
}

