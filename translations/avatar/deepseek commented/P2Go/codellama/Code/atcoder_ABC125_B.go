
package main

import "fmt"

func main() {
	var N int
	fmt.Scan(&N)
	V := make([]int, N)
	C := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&V[i])
	}
	for i := 0; i < N; i++ {
		fmt.Scan(&C[i])
	}
	list := make([]int, 1)
	list[0] = 0
	ans := 0
	X := 0
	Y := 0
	for i := 0; i < N; i++ {
		if V[i]-C[i] > 0 {
			X = V[i]
			Y = C[i]
			list = append(list, X-Y)
		}
	}
	fmt.Println(sum(list))
}

func sum(list []int) int {
	sum := 0
	for _, v := range list {
		sum += v
	}
	return sum
}

