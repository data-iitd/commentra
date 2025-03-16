
package main

import "fmt"

func main() {
	var N, P int
	fmt.Scan(&N, &P)
	fmt.Println(N, P)
	fmt.Println(combi(N, P))
}

func combi(N, K int) int {
	a := 1
	for i := 0; i < K; i++ {
		a *= N - i
	}
	for j := 0; j < K; j++ {
		a /= j + 1
	}
	return a
}

