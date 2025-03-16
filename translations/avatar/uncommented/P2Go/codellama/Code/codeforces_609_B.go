package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	var lst []int
	for i := 0; i < n; i++ {
		var tmp int
		fmt.Scan(&tmp)
		lst = append(lst, tmp)
	}
	l := make(map[int]int)
	for i := 0; i < n; i++ {
		if _, ok := l[lst[i]]; !ok {
			l[lst[i]] = 1
		} else {
			l[lst[i]]++
		}
	}
	res := 0
	for i := 0; i < n; i++ {
		if l[lst[i]] > 1 {
			res += n - i - l[lst[i]]
			l[lst[i]]--
		} else {
			res += n - i - 1
		}
	}
	fmt.Println(res)
}

