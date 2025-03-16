package main

import (
	"fmt"
)

func main() {
	var S string
	fmt.Scan(&S)
	for i := 0; i < len(S); i++ {
		if S[i] == 'A' && i+1 < len(S) && S[i+1] == 'C' {
			fmt.Println("Yes")
			return
		}
	}
	fmt.Println("No")
}

// <END-OF-CODE>
