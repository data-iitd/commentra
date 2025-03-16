
package main

import "fmt"

func main() {
	var x, y, z, k int
	fmt.Scan(&x, &y, &z, &k)
	// Taking four integer inputs: x, y, z, and k

	a := make([]int, x)
	for i := 0; i < x; i++ {
		fmt.Scan(&a[i])
	}
	// Reading list a of integers

	b := make([]int, y)
	for i := 0; i < y; i++ {
		fmt.Scan(&b[i])
	}
	// Reading list b of integers

	c := make([]int, z)
	for i := 0; i < z; i++ {
		fmt.Scan(&c[i])
	}
	// Reading list c of integers

	ab := make([]int, 0)
	// Initializing an empty list ab to store sums of elements from a and b

	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			ab = append(ab, a[i]+b[j])
		}
	}
	// Populating list ab with sums of elements from a and b

	ab = sort(ab, true)
	// Sorting list ab in descending order

	abc := make([]int, 0)
	// Initializing an empty list abc to store sums of elements from ab and c

	for i := 0; i < min(k, x*y); i++ {
		for j := 0; j < z; j++ {
			abc = append(abc, ab[i]+c[j])
		}
	}
	// Populating list abc with sums of elements from ab and c, limited by k

	abc = sort(abc, true)
	// Sorting list abc in descending order

	for i := 0; i < k; i++ {
		fmt.Println(abc[i])
	}
	// Printing the first k elements of abc in descending order
}

func sort(arr []int, desc bool) []int {
	if desc {
		for i := 0; i < len(arr)-1; i++ {
			for j := i + 1; j < len(arr); j++ {
				if arr[i] < arr[j] {
					arr[i], arr[j] = arr[j], arr[i]
				}
			}
		}
	} else {
		for i := 0; i < len(arr)-1; i++ {
			for j := i + 1; j < len(arr); j++ {
				if arr[i] > arr[j] {
					arr[i], arr[j] = arr[j], arr[i]
				}
			}
		}
	}
	return arr
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

