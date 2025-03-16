
package main

import "fmt"

func main() {
	var i, n, s, q, t, count int
	fmt.Scan(&n)
	s = make([]int, n)
	for i = 0; i < n; i++ {
		fmt.Scan(&s[i])
	}
	fmt.Scan(&q)
	count = 0
	for i = 0; i < q; i++ {
		fmt.Scan(&t)
		if linersearch(s, n, t) {
			count++
		}
	}
	fmt.Println(count)
}

func linersearch(a []int, n, key int) bool {
	i := 0
	a[n] = key
	for a[i]!= key {
		i++
	}
	return i!= n
}

