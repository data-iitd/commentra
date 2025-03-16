package main

import (
	"fmt"
)

func main() {
	var N, X int64
	fmt.Scan(&N, &X)

	ans := int64(0)
	min := int64(1000000000)

	for i := int64(0); i < N; i++ {
		var tmp int64
		fmt.Scan(&tmp)
		X -= tmp
		ans++
		if tmp < min {
			min = tmp
		}
	}

	ans += X / min

	fmt.Println(ans)
}

// <END-OF-CODE>
