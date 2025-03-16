package main

import "fmt"

func main() {
	var N, R int

	fmt.Scanf("%d %d", &N, &R)

	if N >= 10 {
		fmt.Printf("%d\n", R)
	} else {
		fmt.Printf("%d\n", R + 100*(10-N))
	}
}

