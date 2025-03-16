package main

import (
	"bufio"
	"fmt"
	"os"
)

const MAXN = 1e5 + 10

var (
	n, m, Q       int
	a             [MAXN]int
	b             [MAXN]int
	id            [MAXN]int
	vis           [MAXN]bool
	cnt           [MAXN]int
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read input
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n, &m)
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &Q)
	for i := 1; i <= Q; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &a[i])
	}

	// Initialize variables
	for k, j := 0, Q; j > 0; j-- {
		if !vis[a[j]] {
			k++
			b[k] = a[j]
			vis[a[j]] = true
		}
	}

	// Fill the output array with the remaining unvisited elements
	for j, i := m, m; i > 0; i-- {
		if !vis[i] {
			j--
			b[j] = i
		}
	}

	// Assign indices to the output array elements
	for i := 1; i <= m; i++ {
		id[b[i]] = i
	}

	// Process queries
	flag := true
	cnt[0] = n
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

	// Check the result
	l := 0
	for ; cnt[l] == 0; l++ {
	}
	for i := l + 1; i < m; i++ {
		if b[i] < b[i+1] {
			flag = false
			break
		}
	}

	// Print the result
	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

