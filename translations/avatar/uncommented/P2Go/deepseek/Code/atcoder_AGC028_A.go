package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
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
	for _, value := range NumberiMN {
		for _, j := range Numberj {
			if math.Abs(value-float64(j)) < 1e-9 {
				Kaburij = append(Kaburij, j)
				break
			}
		}
	}

	Kaburi_i := make([]int, len(Kaburij))
	for _, j := range Kaburij {
		Kaburi_i = append(Kaburi_i, int(float64(j)*float64(N)/float64(M)))
	}

	counter := 0
	Flag := 0
	KaburiSize := len(Kaburi_i)
	for counter <= KaburiSize-1 {
		if listS[Kaburi_i[counter]] != listT[Kaburij[counter]] {
			Flag = 1
			break
		}
		counter++
	}

	if Flag == 1 {
		fmt.Println(-1)
	} else {
		fmt.Println(N * M / gcd(N, M))
	}
}
