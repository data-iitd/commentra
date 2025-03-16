
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Card struct {
	suit string
	val  int
}

func merge(a []Card, l, m, r int) {
	n1 := m - l
	n2 := r - m

	L := make([]Card, n1+1)
	R := make([]Card, n2+1)

	for i := 0; i < n1; i++ {
		L[i] = a[l+i]
	}
	for i := 0; i < n2; i++ {
		R[i] = a[m+i]
	}
	L[n1] = Card{"", 2000000000}
	R[n2] = Card{"", 2000000000}

	i, j := 0, 0
	for k := l; k < r; k++ {
		if L[i].val <= R[j].val {
			a[k] = L[i]
			i++
		} else {
			a[k] = R[j]
			j++
		}
	}
}

func mergeSort(a []Card, l, r int) {
	if l+1 < r {
		m := (l + r) / 2
		mergeSort(a, l, m)
		mergeSort(a, m, r)
		merge(a, l, m, r)
	}
}

func partition(a []Card, p, r int) int {
	x := a[r]
	i := p - 1
	for j := p; j < r; j++ {
		if a[j].val <= x.val {
			i++
			a[i], a[j] = a[j], a[i]
		}
	}
	a[i+1], a[r] = a[r], a[i+1]
	return i + 1
}

func quickSort(a []Card, p, r int) {
	if p < r {
		q := partition(a, p, r)
		quickSort(a, p, q-1)
		quickSort(a, q+1, r)
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())

	cards := make([]Card, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		parts := strings.Split(scanner.Text(), " ")
		cards[i] = Card{parts[0], 0}
		scanner.Scan()
		cards[i].val, _ = strconv.Atoi(scanner.Text())
	}

	mergeSort(cards, 0, n)
	quickSort(cards, 0, n-1)

	stable := true
	for i := 0; i < n-1; i++ {
		if cards[i].suit!= cards[i+1].suit {
			stable = false
			break
		}
	}
	if stable {
		fmt.Println("Stable")
	} else {
		fmt.Println("Not stable")
	}
	for i := 0; i < n; i++ {
		fmt.Printf("%s %d\n", cards[i].suit, cards[i].val)
	}
}
