
package main

import "fmt"

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	var v string
	fmt.Scan(&v)
	var d = []string{"LEFT", "RIGHT"}
	var f = k-1 < n-k
	var m = min(k-1, n-k)
	var a []string
	for i := 0; i < m; i++ {
		a = append(a, d[not f])
	}
	for i := 0; i < len(v); i++ {
		a = append(a, "PRINT "+string(v[i]))
		a = append(a, d[f])
	}
	fmt.Println(a[:len(a)-1]...)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func not(b bool) bool {
	if b {
		return false
	}
	return true
}

