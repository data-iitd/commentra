package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var i int
	var p int
	var r int
	var x string
	var y int
	var tmpN int
	var tmpC string
	var count int
	var MC [100001]string
	var MN [100001]int
	var C [100001]string
	var A [100001]int

	fmt.Scanf("%d\n", &n)

	for i = 1; i <= n; i++ {
		fmt.Scanf("%s %d\n", &C[i], &A[i])
		MC[i] = C[i]
		MN[i] = A[i]
	}

	Merge_Sort(MC, MN, 1, n)

	p = 1
	Quicksort(C, A, p, n)

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
		fmt.Printf("%s %d\n", C[i], A[i])
	}
}

func Partition(C []string, A []int, p int, r int) int {
	var i int
	var j int
	var tmpC string
	var x string
	var tmpN int
	var y int

	x = C[r]
	y = A[r]
	i = p - 1

	for j = p; j < r; j++ {
		if A[j] <= y {
			i = i + 1
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

func Quicksort(C []string, A []int, p int, r int) {
	if p < r {
		q = Partition(C, A, p, r)
		Quicksort(C, A, p, q-1)
		Quicksort(C, A, q+1, r)
	}
}

//Merge_Sortから送られてきたデータを結合する。
func Merge(MC []string, MN []int, left int, mid int, right int) {
	var n1 int
	var n2 int
	var LN [100001]int
	var RN [100001]int
	var LC [100001]string
	var RC [100001]string
	var i int
	var j int
	var k int

	n1 = mid - left + 1
	n2 = right - mid
	for i = 1; i <= n1; i++ {
		LN[i] = MN[left+i-1]
		LC[i] = MC[left+i-1]
	}
	for i = 1; i <= n2; i++ {
		RN[i] = MN[mid+i]
		RC[i] = MC[mid+i]
	}
	LN[n1+1] = 1000000000
	RN[n2+1] = 1000000000
	i = 1
	j = 1
	for k = left; k <= right; k++ {
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

//ここで分割できるだけ分割する
func Merge_Sort(MC []string, MN []int, left int, right int) {
	var mid int

	// 2つになるまで分割して行く
	if left < right {
		mid = (left + right) / 2
		Merge_Sort(MC, MN, left, mid)
		Merge_Sort(MC, MN, mid+1, right)
		Merge(MC, MN, left, mid, right)
	}
}

