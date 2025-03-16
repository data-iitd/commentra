package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a % b
	}
	return a
}

func main() {
	var N, M int
	var S, T string
	fmt.Scan(&N, &M)
	fmt.Scan(&S)
	fmt.Scan(&T)

	listS := []rune(S)
	listT := []rune(T)

	Numberi := make([]int, N)
	for i := 0; i < N; i++ {
		Numberi[i] = i
	}

	NumberiMN := make([]float64, N)
	for i := 0; i < N; i++ {
		NumberiMN[i] = float64(i) * float64(M) / float64(N)
	}

	Numberj := make([]int, M)
	for j := 0; j < M; j++ {
		Numberj[j] = j
	}

	var Kaburij []int
	for _, ni := range NumberiMN {
		for _, nj := range Numberj {
			if math.Abs(ni-float64(nj)) < 1e-9 {
				Kaburij = append(Kaburij, nj)
			}
		}
	}

	var KaburiI []int
	for _, kj := range Kaburij {
		for _, ni := range Numberi {
			if math.Abs(NumberiMN[ni]-float64(kj)) < 1e-9 {
				KaburiI = append(KaburiI, ni)
			}
		}
	}

	counter := 0
	flag := 0
	KaburiSize := len(KaburiI)

	for counter < KaburiSize {
		if listS[KaburiI[counter]] != listT[Kaburij[counter]] {
			flag = 1
			break
		}
		counter++
	}

	if flag == 1 {
		fmt.Println(-1)
	} else {
		fmt.Println(N * M / gcd(N, M))
	}
}
