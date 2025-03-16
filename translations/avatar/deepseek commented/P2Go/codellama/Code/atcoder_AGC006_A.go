
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	s := make([]byte, n)
	t := make([]byte, n)
	fmt.Scan(&s)
	fmt.Scan(&t)
	if s == t {
		fmt.Println(n)
	} else {
		cnt := 0
		for i := 0; i < n; i++ {
			for j := 0; j < n-i; j++ {
				if s[i+j] != t[j] {
					break
				}
				if j == n-i-1 {
					cnt = n - i
				}
			}
		}
		fmt.Println(2*n - cnt)
	}
}

