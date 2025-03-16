package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	s := []string{}
	for i := 0; i < n; i++ {
		var k string
		fmt.Scan(&k)
		s = append(s, k)
	}

	flag := 0
	d1 := []rune{}
	d2 := []rune{}
	rem := make(map[rune]bool)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i == j {
				d1 = append(d1, []rune(s[i])[j])
			}
			if i == n-j-1 {
				d2 = append(d2, []rune(s[i])[j])
			}
			if i != j && i != n-j-1 {
				rem[[]rune(s[i])[j]] = true
			}
		}
	}

	if len(rem) != 1 {
		fmt.Println("NO")
	} else if !equal(d1, d2) {
		fmt.Println("NO")
	} else if len(unique(d1)) != 1 {
		fmt.Println("NO")
	} else if unique(d1)[0] == unique(d1)[0] {
		fmt.Println("NO")
	} else {
		fmt.Println("YES")
	}
}

func equal(a, b []rune) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func unique(arr []rune) []rune {
	uniqueMap := make(map[rune]bool)
	for _, num := range arr {
		uniqueMap[num] = true
	}
	uniqueArr := []rune{}
	for num := range uniqueMap {
		uniqueArr = append(uniqueArr, num)
	}
	return uniqueArr
}

