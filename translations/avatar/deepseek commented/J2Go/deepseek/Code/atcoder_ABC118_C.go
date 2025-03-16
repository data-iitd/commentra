package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	if n == 1 {
		var single int
		fmt.Scan(&single)
		fmt.Println(single)
		return
	}

	var a []int
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		a = append(a, num)
	}

	sort.Ints(a)

	if a[len(a)-1] == 0 {
		fmt.Println(0)
		return
	}

	var ans int

	for {
		if len(a) == 1 {
			ans = a[0]
			break
		}
		a = func(A []int) []int {
			var a []int = A
			min := 0

			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min != 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return nil
						}
					} else {
						min = a[i]
					}
				}
			}

			sort.Ints(a)
			return a
		}(a)
	}

	fmt.Println(ans)
}

