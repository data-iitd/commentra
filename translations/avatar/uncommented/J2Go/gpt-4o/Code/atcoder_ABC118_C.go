package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, 0)

	if n == 1 {
		var single int
		fmt.Scan(&single)
		fmt.Println(single)
		return
	}

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
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...) // Remove element
					i-- // Adjust index after removal
				} else {
					if min != 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return nil // Exit the program
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

// <END-OF-CODE>
