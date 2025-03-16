
package main

import "fmt"

func main() {
	var T, S, q int
	fmt.Scan(&T, &S, &q)
	var previous int64 = int64(S)
	var answer int
	for previous < int64(T) {
		answer++
		previous *= q
	}
	fmt.Println(answer)
}

