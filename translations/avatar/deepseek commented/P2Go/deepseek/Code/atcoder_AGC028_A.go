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
	fmt.Scan(&N, &M)

	var S, T string
	fmt.Scan(&S)
	fmt.Scan(&T)

	listS := []rune(S)
	listT := []rune(T)

	Number_i := make([]int, N)
	for i := 0; i < N; i++ {
		Number_i[i] = i
	}

	Number_iMN := make([]float64, N)
	for i := 0; i < N; i++ {
		Number_iMN[i] = float64(i) * float64(M) / float64(N)
	}

	Number_j := make([]int, M)
	for j := 0; j < M; j++ {
		Number_j[j] = j
	}

	var Kaburi_j []int
	for _, j := range Number_j {
		if math.Mod(Number_iMN[int(j)*N/M], 1) == 0 {
			Kaburi_j = append(Kaburi_j, j)
		}
	}

	Kaburi_i := make([]int, len(Kaburi_j))
	for k, j := range Kaburi_j {
		Kaburi_i[k] = int(j) * N / M
	}

	counter := 0
	Flag := 0
	Kaburi_Size := len(Kaburi_i)

	for counter < Kaburi_Size {
		if listS[Kaburi_i[counter]] != listT[Kaburi_j[counter]] {
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
