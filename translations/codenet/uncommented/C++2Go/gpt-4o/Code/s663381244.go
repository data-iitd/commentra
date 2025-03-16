package main

import (
	"fmt"
)

func main() {
	m := []int{10, 50, 100, 500}

	first := true
	var money int

	for {
		_, err := fmt.Scan(&money)
		if err != nil || money == 0 {
			break
		}

		if !first {
			fmt.Println()
		}
		first = false

		sum := 0
		num := make([]int, 4)

		for i := 0; i < 4; i++ {
			fmt.Scan(&num[i])
			sum += num[i] * m[i]
		}

		change := sum - money
		for i := 3; i >= 0; i-- {
			if change/m[i] > 0 {
				num[i] -= change / m[i]
				change %= m[i]
			}
		}

		for i := 0; i < 4; i++ {
			if num[i] > 0 {
				fmt.Printf("%d %d\n", m[i], num[i])
			}
		}
	}
}

// <END-OF-CODE>
