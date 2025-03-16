
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
	reader := bufio.NewReader(os.Stdin)

	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	a := make([]card, n)
	b := make([]card, n)

	for i := 0; i < n; i++ {
		fields := strings.Fields(readLine(reader))
		a[i] = card{s: fields[0], v: mustParseInt(fields[1])}
		b[i] = card{s: fields[0], v: mustParseInt(fields[1])}
	}

	mergeSort(a, 0, n)
	quickSort(b, 0, n-1)

	stable := true
	for i := 0; i < n; i++ {
		if a[i].s!= b[i].s {
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
		fmt.Printf("%s %d\n", b[i].s, b[i].v)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}

	panic(err)
}

func mustParseInt(s string) int {
	n, err := strconv.Atoi(s)
	if err!= nil {
		panic(err)
	}
	return n
}

func merge(a []card, n int, l int, m int, r int) {
	n1 := m - l
	n2 := r - m

	for i := 0; i < n1; i++ {
		a[l+i] = card{s: "", v: 2000000000}
	}
	for i := 0; i < n2; i++ {
		a[m+i] = card{s: "", v: 2000000000}
	}

	i := 0
	j := 0

	for k := l; k < r; k++ {
		if a[l+i].v <= a[m+j].v {
			a[k] = a[l+i]
			i++
		} else {
			a[k] = a[m+j]
			j++
		}
	}
}

func mergeSort(a []card, n int, l int, r int) {
	if l + 1 < r {
		m := (l + r) / 2
		mergeSort(a, n, l, m)
		mergeSort(a, n, m, r)
		merge(a, n, l, m, r)
	}
}

func partition(a []card, n int, p int, r int) int {
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

func quickSort(a []card, n int, p int, r int) {
	if p < r {
		q := partition(a, n, p, r)
		quickSort(a, n, p, q-1)
		quickSort(a, n, q+1, r)
	}
}

// END-OF-CODE