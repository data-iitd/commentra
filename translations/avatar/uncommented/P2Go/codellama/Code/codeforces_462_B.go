
package main

import "fmt"

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	s := make([]byte, n)
	fmt.Scan(&s)
	count := make([]int, 26)
	for _, c := range s {
		count[c-'A']++
	}
	for i := 25; i >= 0; i-- {
		if count[i] >= k {
			fmt.Println(k * k)
			return
		}
		k -= count[i]
	}
	res := 0
	for i := 25; i >= 0; i-- {
		res += count[i] * count[i]
	}
	fmt.Println(res)
}

