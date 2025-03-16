
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
	count = sort(count)
	res := 0
	for i := 0; i < 26; i++ {
		if count[i] >= k {
			res += k * k
			fmt.Println(res)
			return
		}
		k -= count[i]
		res += count[i] * count[i]
	}
	fmt.Println(res)
}

func sort(count []int) []int {
	for i := 0; i < len(count)-1; i++ {
		for j := i + 1; j < len(count); j++ {
			if count[i] < count[j] {
				count[i], count[j] = count[j], count[i]
			}
		}
	}
	return count
}

