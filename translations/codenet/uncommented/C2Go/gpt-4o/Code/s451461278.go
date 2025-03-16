package main

import (
	"fmt"
)

const MAX = 100000

var q int

func Partition(C []rune, A []int, p int, r int) int {
	var i, j int
	var tmpC rune
	var x rune
	var tmpN int
	var y int

	x = C[r]
	y = A[r]
	i = p - 1

	for j = p; j < r; j++ {
		if A[j] <= y {
			i++
			tmpN = A[j]
			tmpC = C[j]
			A[j] = A[i]
			C[j] = C[i]
			A[i] = tmpN
			C[i] = tmpC
		}
	}

	tmpN = A[i+1]
	tmpC = C[i+1]
	A[i+1] = A[r]
	C[i+1] = C[r]
	A[r] = tmpN
	C[r] = tmpC

	return i + 1
}

func Quicksort(C []rune, A []int, p int, r int) {
	if p < r {
		q = Partition(C, A, p, r)
		Quicksort(C, A, p, q-1)
		Quicksort(C, A, q+1, r)
	}
}

func Merge(MC []rune, MN []int, left int, mid int, right int) {
	n1 := mid - left + 1
	n2 := right - mid
	LN := make([]int, n1+1)
	RN := make([]int, n2+1)
	LC := make([]rune, n1+1)
	RC := make([]rune, n2+1)

	for i := 1; i <= n1; i++ {
		LN[i] = MN[left+i-1]
		LC[i] = MC[left+i-1]
	}

	for i := 1; i <= n2; i++ {
		RN[i] = MN[mid+i]
		RC[i] = MC[mid+i]
	}

	LN[n1+1] = 1000000000
	RN[n2+1] = 1000000000

	i := 1
	j := 1

	for k := left; k <= right; k++ {
		if LN[i] <= RN[j] {
			MN[k] = LN[i]
			MC[k] = LC[i]
			i++
		} else {
			MN[k] = RN[j]
			MC[k] = RC[j]
			j++
		}
	}
}

func MergeSort(MC []rune, MN []int, left int, right int) {
	if left < right {
		mid := (left + right) / 2
		MergeSort(MC, MN, left, mid)
		MergeSort(MC, MN, mid+1, right)
		Merge(MC, MN, left, mid, right)
	}
}

func main() {
	var A [MAX + 1]int
	var C [MAX + 1]rune
	var MC [MAX + 1]rune
	var MN [MAX + 1]int

	var n int
	var count int

	fmt.Scan(&n)

	for i := 1; i <= n; i++ {
		var ch rune
		var num int
		fmt.Scanf(" %c %d", &ch, &num)
		C[i] = ch
		A[i] = num
	}

	for i := 1; i <= n; i++ {
		MC[i] = C[i]
		MN[i] = A[i]
	}

	MergeSort(MC[:], MN[:], 1, n)

	p := 1
	Quicksort(C[:], A[:], p, n)

	for i := 1; i <= n; i++ {
		if MN[i] == A[i] && MC[i] == C[i] {
			count++
		}
	}

	if count == n {
		fmt.Println("Stable")
	} else {
		fmt.Println("Not stable")
	}

	for i := 1; i <= n; i++ {
		fmt.Printf("%c %d\n", C[i], A[i])
	}
}

// <END-OF-CODE>
