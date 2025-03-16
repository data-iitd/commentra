package main

import (
	"fmt"
)

func main() {
	var i int
	var S [6]string

	fmt.Scan(&S)

	for i = 0; i < len(S); i++ {
		if S[i] == "A" && S[i+1] == "C" {
			fmt.Println("Yes")
			return
		}
	}

	fmt.Println("No")
}

