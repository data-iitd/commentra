
package main

import "fmt"

func main() {
	var x, y, z, k int
	fmt.Scan(&x, &y, &z, &k)
	a := make([]int, x)
	b := make([]int, y)
	c := make([]int, z)
	for i := 0; i < x; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < y; i++ {
		fmt.Scan(&b[i])
	}
	for i := 0; i < z; i++ {
		fmt.Scan(&c[i])
	}
	ab := make([]int, x*y)
	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			ab[i*y+j] = a[i] + b[j]
		}
	}
	ab = append(ab, 0)
	abc := make([]int, k)
	for i := 0; i < k; i++ {
		for j := 0; j < z; j++ {
			abc[i] = ab[i] + c[j]
		}
	}
	abc = append(abc, 0)
	for i := 0; i < k; i++ {
		fmt.Println(abc[i])
	}
}

