
package main

import "fmt"

func swap(a *int, b *int) {
	tmp := *a
	*a = *b
	*b = tmp
}

func main() {
	var a, b int
	for {
		fmt.Scan(&a, &b)
		if a == 0 && b == 0 {
			break
		}
		if b < a {
			swap(&a, &b)
		}
		fmt.Printf("%d %d\n", a, b)
	}
}

