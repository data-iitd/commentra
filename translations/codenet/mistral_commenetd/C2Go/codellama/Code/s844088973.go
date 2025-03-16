
package main

import "fmt"

func main() {
	var K, X int
	fmt.Scanf("%d %d", &K, &X)

	for i := X - K + 1; i <= X+K-1; i++ {
		fmt.Printf("%d", i)
		if i < X+K-1 {
			fmt.Printf(" ")
		}
	}
	fmt.Printf("\n")
}

