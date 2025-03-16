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
		Number_iMN[i] = float64(i * M) / float64(N)
	}

	Number_j := make([]int, M)
	for j := 0; j < M; j++ {
		Number_j[j] = j
	}

	kaburi_j := make(map[int]struct{})
	for _, num := range Number_iMN {
		kaburi_j[int(num)] = struct{}{}
	}

	kaburi_i := []int{}
	for j := 0; j < M; j++ {
		if _, exists := kaburi_j[j]; exists {
			kaburi_i = append(kaburi_i, int(float64(j*N)/float64(M)))
		}
	}

	flag := 0
	kaburiSize := len(kaburi_i)
	for counter := 0; counter < kaburiSize; counter++ {
		if listS[kaburi_i[counter]] != listT[Number_j[counter]] {
			flag = 1
			break
		}
	}

	if flag == 1 {
		fmt.Println(-1)
	} else {
		fmt.Println(int(float64(N*M) / float64(gcd(N, M))))
	}
}

// <END-OF-CODE>
