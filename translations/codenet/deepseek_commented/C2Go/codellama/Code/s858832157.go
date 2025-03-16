package main

import "fmt"

func main() {
	var i int = 1
	var Input int

	for {
		fmt.Scanf("%d", &Input)
		if Input == 0 {
			break
		}
		fmt.Printf("Case %d: %d\n", i, Input)
		i++
	}
}

