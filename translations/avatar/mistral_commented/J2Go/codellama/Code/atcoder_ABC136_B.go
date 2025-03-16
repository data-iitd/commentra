package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)

	count := 0
	temp := N

	for temp > 0 {
		temp /= 10
		count++
	}

	ans := 0
	for i := 1; i <= count; i++ {
		if i == count {
			if i%2 == 1 {
				ans += (N - int(math.Pow10(i-1)) + 1)
			}
		} else {
			if i == 1 {
				ans += 9
			} else if i%2 == 1 {
				ans += int(math.Pow10(i)) - int(math.Pow10(i-1))
			}
		}
	}

	fmt.Println(ans)
}

