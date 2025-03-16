
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	var s string
	fmt.Scan(&s)
	cnt := 0
	for i := 0; i < n; i++ {
		cnt++
		j := i + 1
		for ; j < n; j++ {
			if s[i]!= s[j] {
				break
			}
		}
		i = j - 1
	}
	fmt.Println(cnt)
}

