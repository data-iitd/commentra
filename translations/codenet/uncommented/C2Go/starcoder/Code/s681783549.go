package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	var S string
	fmt.Scanf("%s", &S)
	for i := 0; i < len(S); i++ {
		if S[i] == 'A' && S[i+1] == 'C' {
			fmt.Println("Yes")
			os.Exit(0)
		}
	}
	fmt.Println("No")
}

