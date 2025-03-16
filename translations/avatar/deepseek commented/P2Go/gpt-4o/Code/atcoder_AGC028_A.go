package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	for b > 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	var N, M int
	fmt.Scan(&N, &M) // Read the values of N and M

	var S, T string
	fmt.Scan(&S) // Read the string S
	fmt.Scan(&T) // Read the string T

	listS := []rune(S) // Convert string S to a slice of runes (characters)
	listT := []rune(T) // Convert string T to a slice of runes (characters)

	Number_i := make([]int, N)
	for i := 0; i < N; i++ {
		Number_i[i] = i
	}

	Number_iMN := make([]float64, N)
	for i := 0; i < N; i++ {
		Number_iMN[i] = float64(i * M) / float64(N)
	}

	Number_j := make([]int, M)
	for j := 0; j < M; j++ {
		Number_j[j] = j
	}

	Kaburi_j := make(map[int]struct{})
	for _, j := range Number_j {
		Kaburi_j[j] = struct{}{}
	}

	Kaburi_i := []int{}
	for _, i := range Number_iMN {
		if _, exists := Kaburi_j[int(i)]; exists {
			Kaburi_i = append(Kaburi_i, int(i*float64(N)/float64(M)))
		}
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
		fmt.Println(int(float64(N*M) / float64(gcd(N, M))))
	}
}

// <END-OF-CODE>
