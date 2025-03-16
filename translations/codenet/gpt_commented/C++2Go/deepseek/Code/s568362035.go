package main

import (
	"bufio"
	"fmt"
	"os"
)

const MAXN = 1e5 + 10

var (
	n, m, Q   int
	a         [MAXN]int
	b         [MAXN]int
	id        [MAXN]int
	vis       [MAXN]bool
	cnt       [MAXN]int
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read the number of elements (n) and the maximum value (m)
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n, &m)
	// Read the number of queries (Q)
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &Q)

	// Read the queries into array a
	for i := 1; i <= Q; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &a[i])
	}

	// Process the queries to fill array b with unique values from a
	for k, j := 0, Q; j > 0; j-- {
		if !vis[a[j]] {
			k++
			b[k] = a[j]
			vis[a[j]] = true
		}
	}

	// Fill the remaining positions in b with the largest unused values up to m
	for j, i := m, m; i > 0; i-- {
		if !vis[i] {
			j--
			b[j] = i
		}
	}

	// Map each value in b to its index in id
	for i := 1; i <= m; i++ {
		id[b[i]] = i
	}

	flag := true
	cnt[0] = n

	// Process the queries in reverse order
	for i := Q; i > 0; i-- {
		t := id[a[i]]
		if cnt[t-1] > 0 {
			cnt[t-1]--
			cnt[t]++
			vis[t] = true
		} else if !vis[t] {
			flag = false
			break
		}
	}

	// Find the first index l where count is non-zero
	l := 0
	for cnt[l] == 0 {
		l++
	}

	// Check if the remaining values in b are in increasing order
	for i := l + 1; i < m; i++ {
		if b[i] >= b[i+1] {
			flag = false
			break
		}
	}

	// Output the result based on the flag
	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

