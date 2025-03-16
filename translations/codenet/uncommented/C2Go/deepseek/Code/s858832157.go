package main

import (
	"fmt"
)

func main() {
	var i int = 1
	for {
		var Input int
		fmt.Scan(&Input)
		if Input == 0 {
			break
		}
		fmt.Printf("Case %d: %d\n", i, Input)
		i++
	}
}

