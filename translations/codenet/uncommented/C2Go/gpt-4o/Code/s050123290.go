package main

import (
	"fmt"
	"os"
)

const N = 1000

func main() {
	var su [N]rune
	var susum int

	for {
		j := 0
		for j < N {
			_, err := fmt.Scanf("%c", &su[j])
			if err != nil {
				fmt.Println("Error reading input:", err)
				os.Exit(1)
			}
			if su[j] == '\n' {
				break
			}
			susum += int(su[j] - '0')
			j++
		}
		if su[0] == '0' {
			break
		}
		fmt.Println(susum)
		susum = 0
	}
}

// <END-OF-CODE>
