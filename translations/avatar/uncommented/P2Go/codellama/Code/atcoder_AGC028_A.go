
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)
	S := make([]byte, N)
	T := make([]byte, M)
	fmt.Scan(&S)
	fmt.Scan(&T)
	list_S := strings.Split(string(S), "")
	list_T := strings.Split(string(T), "")
	Number_i := make([]int, N)
	for i := 0; i < N; i++ {
		Number_i[i] = i
	}
	Number_iMN := make([]int, 0)
	for i := 0; i < N; i++ {
		Number_iMN = append(Number_iMN, i*M/N)
	}
	Number_j := make([]int, M)
	for j := 0; j < M; j++ {
		Number_j[j] = j
	}
	Kaburi_j := make([]int, 0)
	for _, j := range Number_j {
		if contains(Number_iMN, j) {
			Kaburi_j = append(Kaburi_j, j)
		}
	}
	Kaburi_i := make([]int, 0)
	for _, j := range Kaburi_j {
		Kaburi_i = append(Kaburi_i, int(j*N/M))
	}
	counter := 0
	Flag := 0
	Kaburi_Size := len(Kaburi_i)
	for counter < Kaburi_Size {
		if list_S[Kaburi_i[counter]] == list_T[Kaburi_j[counter]] {
			counter++
		} else {
			Flag = 1
			break
		}
	}
	if Flag == 1 {
		fmt.Println(-1)
	} else {
		fmt.Println(int(N * M / gcd(N, M)))
	}
}

func contains(s []int, e int) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

func gcd(a, b int) int {
	for b > 0 {
		a, b = b, a%b
	}
	return a
}

