package main

import (
	"fmt"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	balls := make([][2]int, N)
	for i := range balls {
		balls[i] = [2]int{1, 0}
	}
	balls[0] = [2]int{0, 1}

	for i := 0; i < M; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		wX, rX := balls[x-1][0], balls[x-1][1]
		wY, rY := balls[y-1][0], balls[y-1][1]

		if wX >= 1 && rX >= 1 {
			balls[x-1][0]--
			balls[y-1][1]++
		} else if wX == 0 {
			balls[x-1][1]--
			balls[y-1][1]++
		} else {
			balls[x-1][0]--
			balls[y-1][0]++
		}
	}

	ans := 0
	for i := 0; i < N; i++ {
		if balls[i][1] > 0 {
			ans++
		}
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
