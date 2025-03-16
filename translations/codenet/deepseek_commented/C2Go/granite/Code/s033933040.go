
package main

import "fmt"

func main() {
	var a, b, mawari, menseki int
	fmt.Scan(&a, &b)
	mawari = 2 * (a + b)
	menseki = a * b
	fmt.Printf("%d %d\n", menseki, mawari)
}
