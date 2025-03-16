package main

import (
	"fmt"
)

const MAX = 100000

// Function declarations
func Partition(C []rune, A []int, p, r int) int {
	i, j := p-1, p
	x, y := C[r], A[r]
	for j < r {
		if A[j] <= y {
			i++
			A[i], A[j] = A[j], A[i]
			C[i], C[j] = C[j], C[i]
		}
		j++
	}
	A[i+1], A[r] = A[r], A[i+1]
	C[i+1], C[r] = C[r], C[i+1]
	return i + 1
}

func Quicksort(C []rune, A []int, p, r int) {
	if p < r {
		q := Partition(C, A, p, r)
		Quicksort(C, A, p, q-1)
		Quicksort(C, A, q+1, r)
	}
}

func Merge(MC []rune, MN []int, left, mid, right int) {
	n1, n2 := mid-left+1, right-mid
	LN, RN := make([]int, n1+1), make([]int, n2+1)
	LC, RC := make([]rune, n1+1), make([]rune, n2+1)
	for i := 0; i < n1; i++ {
		LN[i], LC[i] = MN[left+i], MC[left+i]
	}
	for i := 0; i < n2; i++ {
		RN[i], RC[i] = MN[mid+i+1], MC[mid+i+1]
	}
	LN[n1], RN[n2] = 1000000000, 1000000000
	i, j, k := 0, 0, left
	for i < n1 && j < n2 {
		if LN[i] <= RN[j] {
			MN[k], MC[k] = LN[i], LC[i]
			i++
		} else {
			MN[k], MC[k] = RN[j], RC[j]
			j++
		}
		k++
	}
	for i < n1 {
		MN[k], MC[k] = LN[i], LC[i]
		i++
		k++
	}
	for j < n2 {
		MN[k], MC[k] = RN[j], RC[j]
		j++
		k++
	}
}

func MergeSort(MC []rune, MN []int, left, right int) {
	if left < right {
		mid := (left + right) / 2
		MergeSort(MC, MN, left, mid)
		MergeSort(MC, MN, mid+1, right)
		Merge(MC, MN, left, mid, right)
	}
}

// Main function
func main() {
	C := make([]rune, MAX+1)
	A := make([]int, MAX+1)
	MC := make([]rune, MAX+1)
	MN := make([]int, MAX+1)

	var i, p, n int
	var count int

	fmt.Scan(&n)
	for i = 1; i <= n; i++ {
		fmt.Scanf(" %c %d", &C[i], &A[i])
	}
	for i = 1; i <= n; i++ {
		MC[i], MN[i] = C[i], A[i]
	}

	MergeSort(MC, MN, 1, n)
	p = 1
	Quicksort(C, A, p, n)

	count = 0
	for i = 1; i <= n; i++ {
		if MN[i] == A[i] && MC[i] == C[i] {
			count++
		}
	}

	if count == n {
		fmt.Println("Stable")
	} else {
		fmt.Println("Not stable")
	}

	for i = 1; i <= n; i++ {
		fmt.Printf("%c %d\n", C[i], A[i])
	}
}

