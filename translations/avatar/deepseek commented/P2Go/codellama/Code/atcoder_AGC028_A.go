
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)
	S := ""
	fmt.Scan(&S)
	T := ""
	fmt.Scan(&T)
	list_S := strings.Split(S, "")
	list_T := strings.Split(T, "")
	Number_i := make([]int, N)
	for i := 0; i < N; i++ {
		Number_i[i] = i
	}
	Number_iMN := make([]int, N)
	for i := 0; i < N; i++ {
		Number_iMN[i] = i * M / N
	}
	Number_j := make([]int, M)
	for j := 0; j < M; j++ {
		Number_j[j] = j
	}
	Kaburi_j := make([]int, 0)
	for _, j := range Number_j {
		for _, i := range Number_iMN {
			if j == i {
				Kaburi_j = append(Kaburi_j, j)
			}
		}
	}
	Kaburi_i := make([]int, 0)
	for _, j := range Kaburi_j {
		for _, i := range Number_i {
			if j == i*M/N {
				Kaburi_i = append(Kaburi_i, i)
			}
		}
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
		fmt.Println(N * M / gcd(N, M))
	}
}

func gcd(a, b int) int {
	for b > 0 {
		a, b = b, a%b
	}
	return a
}

