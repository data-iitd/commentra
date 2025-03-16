
package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	var sa int
	fmt.Scan(&sa)
	sa = min(n-sa, sa)
	ss := make([]string, m)
	for i := 0; i < m; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		b -= a
		if b%2 == 0 && b <= sa<<1 {
			ss[i] = "1\n"
		} else {
			ss[i] = "0\n"
		}
	}
	fmt.Print(strings.Join(ss, ""))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

