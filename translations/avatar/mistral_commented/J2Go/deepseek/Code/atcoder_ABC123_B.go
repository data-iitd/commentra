package main

import (
	"fmt"
	"sort"
)

func main() {
	var a [5]int
	var r [5]int
	mapa := make(map[int]int)

	// Reading input elements of array 'a' and storing their remainders in array 'r'
	for i := 0; i < len(a); i++ {
		fmt.Scan(&a[i])
		r[i] = a[i] % 10

		b := 10
		if r[i] != 0 {
			b = 10 - r[i]
			mapa[b] = a[i]
		}
	}

	ans := 0

	// Checking if the map is empty
	if len(mapa) == 0 {
		for i := 0; i < len(a); i++ {
			ans += a[i]
		}
		fmt.Println(ans)
		return
	}

	keys := make([]int, 0, len(mapa))
	for k := range mapa {
		keys = append(keys, k)
	}
	sort.Ints(keys)

	last := mapa[keys[len(keys)-1]]
	idx := 0

	// Finding the index of the last element in array 'a'
	for i := 0; i < len(a); i++ {
		if a[i] == last {
			idx = i
			break
		}
	}

	// Calculating the sum of all elements in array 'a' except the last one
	for i := 0; i < len(a); i++ {
		if i != idx {
			if a[i]%10 == 0 {
				ans += a[i]
			} else {
				ans += a[i] + (10 - r[i])
			}
		}
	}

	// Adding the last element of array 'a' to the sum 'ans'
	ans += last

	fmt.Println(ans)
}
