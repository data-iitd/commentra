package main

import (
	"fmt"
	"math/bits"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	li := make([][]int, m)
	for i := 0; i < m; i++ {
		var k int
		fmt.Scan(&k)
		li[i] = make([]int, k)
		for j := 0; j < k; j++ {
			fmt.Scan(&li[i][j])
		}
	}

	p := make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Scan(&p[i])
	}

	q := make(map[int]struct{})
	for _, sublist := range li {
		for _, val := range sublist {
			q[val] = struct{}{}
		}
	}

	r := make(map[int]struct{})
	for i := 1; i <= n; i++ {
		r[i] = struct{}{}
	}

	for k := range q {
		delete(r, k)
	}

	v := make([]int, 0, len(r))
	for k := range r {
		v = append(v, k)
	}

	ans := 0
	qSlice := make([]int, 0, len(q))
	for k := range q {
		qSlice = append(qSlice, k)
	}

	for i := 0; i <= len(qSlice); i++ {
		combinations := combinations(qSlice, i)
		for _, s := range combinations {
			sSet := make(map[int]struct{})
			for _, val := range s {
				sSet[val] = struct{}{}
			}

			valid := true
			for j, u := range li {
				count := 0
				for _, val := range u {
					if _, exists := sSet[val]; exists {
						count++
					}
				}
				if count%2 != p[j] {
					valid = false
					break
				}
			}

			if valid {
				ans += 1 << len(v) // 2 ** len(v)
			}
		}
	}

	fmt.Println(ans)
}

func combinations(arr []int, r int) [][]int {
	var result [][]int
	n := len(arr)
	if r > n {
		return result
	}
	data := make([]int, r)
	var combine func(int, int)
	combine = func(start, index int) {
		if index == r {
			temp := make([]int, r)
			copy(temp, data)
			result = append(result, temp)
			return
		}
		for i := start; i <= n-(r-index); i++ {
			data[index] = arr[i]
			combine(i+1, index+1)
		}
	}
	combine(0, 0)
	return result
}

// <END-OF-CODE>
