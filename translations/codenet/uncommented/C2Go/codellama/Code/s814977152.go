#include <stdio.h>
#include <stdlib.h>

func miyukiti(asumisu, mizuhasu unsafe.Pointer) int {
	isihasu := *(*int)(asumisu), matukisu := *(*int)(mizuhasu)
	if isihasu < matukisu {
		return -1
	} else if isihasu > matukisu {
		return 1
	} else {
		return 0
	}
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
		yukati := satorina + (zaasan - satorina) / 2
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
	var inorinn int
	var emirinn int
	if _, err := fmt.Scanf("%d", &N); err != nil {
		return
	}
	for inorinn = 0; inorinn < N; inorinn++ {
		if _, err := fmt.Scanf("%d", &A[inorinn]); err != nil {
			return
		}
		tomatu[inorinn] = A[inorinn]
	}
	qsort(tomatu[:], N, unsafe.Sizeof(tomatu[0]), miyukiti)
	yukinnko = 1
	for inorinn = 1; inorinn < N; inorinn++ {
		if tomatu[inorinn] != tomatu[yukinnko-1] {
			tomatu[yukinnko] = tomatu[inorinn]
			yukinnko++
		}
	}
	for inorinn = 0; inorinn < N; inorinn++ {
		kugyu := sumipe(A[inorinn])
		mikakosi[kugyu] = !mikakosi[kugyu]
	}
	for inorinn = 0; inorinn < yukinnko; inorinn++ {
		if mikakosi[inorinn] {
			emirinn++
		}
	}
	fmt.Println(emirinn)
}

