package main

import (
	"fmt"
	"sort"
)

func I() int {
	var x int
	fmt.Scan(&x)
	return x
}

func LI() []int {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	return arr
}

func main() {
	N := I()
	S := LI()
	sort.Sort(sort.Reverse(sort.IntSlice(S)))

	flag := make([]bool, len(S))
	cur := []int{S[0]}
	flag[0] = false

	for i := 0; i < N; i++ {
		j := 0
		jM := len(cur)
		for k := 0; k < len(S); k++ {
			if flag[k] && S[k] < cur[j] {
				cur = append(cur, S[k])
				j++
				flag[k] = false
				if j == jM {
					break
				}
			}
		}
		if j < jM {
			fmt.Println("No")
			return
		}
		sort.Sort(sort.Reverse(sort.IntSlice(cur)))
	}
	fmt.Println("Yes")
}

// <END-OF-CODE>
