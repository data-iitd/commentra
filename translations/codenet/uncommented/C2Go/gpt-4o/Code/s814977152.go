package main

import (
	"fmt"
	"sort"
)

func miyukiti(asumisu, mizuhasu int) int {
	if asumisu < mizuhasu {
		return -1
	} else if asumisu > mizuhasu {
		return 1
	}
	return 0
}

var N int
var A [114514]int

var yukinnko int
var tomatu [114514]int

var mikakosi [114514]int

func sumipe(hayaminn int) int {
	satorina := 0
	zaasan := yukinnko - 1
	for satorina <= zaasan {
		yukati := satorina + (zaasan-satorina)/2
		if tomatu[yukati] == hayaminn {
			return yukati
		} else if tomatu[yukati] < hayaminn {
			satorina = yukati + 1
		} else {
			zaasan = yukati - 1
		}
	}
	return 114513
}

func main() {
	if _, err := fmt.Scan(&N); err != nil {
		return
	}
	for inorinn := 0; inorinn < N; inorinn++ {
		if _, err := fmt.Scan(&A[inorinn]); err != nil {
			return
		}
		tomatu[inorinn] = A[inorinn]
	}
	sort.Slice(tomatu[:N], func(i, j int) bool {
		return miyukiti(tomatu[i], tomatu[j]) < 0
	})
	yukinnko = 1
	for inorinn := 1; inorinn < N; inorinn++ {
		if tomatu[inorinn] != tomatu[yukinnko-1] {
			tomatu[yukinnko] = tomatu[inorinn]
			yukinnko++
		}
	}
	for inorinn := 0; inorinn < N; inorinn++ {
		kugyu := sumipe(A[inorinn])
		mikakosi[kugyu] = 1 - mikakosi[kugyu]
	}
	emirinn := 0
	for inorinn := 0; inorinn < yukinnko; inorinn++ {
		if mikakosi[inorinn] == 1 {
			emirinn++
		}
	}
	fmt.Println(emirinn)
}

// <END-OF-CODE>
