

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type card struct {
	s string
	v int
}

func main() {
	// Read input from standard input.
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	a := make([]card, n)
	b := make([]card, n)
	for i := 0; i < n; i++ {
		fields := strings.Fields(readLine(reader))
		a[i].s = fields[0][0]
		a[i].v, _ = strconv.Atoi(fields[1])
		b[i].s = fields[0][0]
		b[i].v, _ = strconv.Atoi(fields[1])
	}

	// Merge sort the 'a' array.
	mergeSort(a, 0, n)

	// Quick sort the 'b' array.
	quickSort(b, 0, n-1)

	// Check stability of the sorting algorithms.
	stable := true
	for i := 0; i < n; i++ {
		if a[i].s!= b[i].s {
			stable = false
			break
		}
	}

	// Print the result and the sorted array 'b'.
	if stable {
		fmt.Println("Stable")
	} else {
		fmt.Println("Not stable")
	}
	for i := 0; i < n; i++ {
		fmt.Printf("%c %d\n", b[i].s, b[i].v)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

func merge(a []card, l, m, r int) {
	n1 := m - l
	n2 := r - m
	L := make([]card, n1+1)
	R := make([]card, n2+1)
	copy(L, a[l:m])
	copy(R, a[m:r])
	L[n1] = card{"$", 2000000000}
	R[n2] = card{"$", 2000000000}
	i, j := 0, 0
	for k := l; k < r; k++ {
		if L[i].v <= R[j].v {
			a[k] = L[i]
			i++
		} else {
			a[k] = R[j]
			j++
		}
	}
}

func mergeSort(a []card, l, r int) {
	if l < r {
		m := (l + r) / 2
		mergeSort(a, l, m)
		mergeSort(a, m, r)
		merge(a, l, m, r)
	}
}

func partition(a []card, p, r int) int {
	x := a[r]
	i := p - 1
	for j := p; j < r; j++ {
		if a[j].v <= x.v {
			i++
			a[i], a[j] = a[j], a[i]
		}
	}
	a[i+1], a[r] = a[r], a[i+1]
	return i + 1
}

func quickSort(a []card, p, r int) {
	if p < r {
		q := partition(a, p, r)
		quickSort(a, p, q-1)
		quickSort(a, q+1, r)
	}
}

This Go code implements the merge sort and quick sort algorithms to sort the input cards. It reads the input from standard input, sorts the 'a' and 'b' arrays using merge sort and quick sort, and checks the stability of the sorting algorithms. Finally, it prints the result and the sorted array 'b'.