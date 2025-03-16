
package main

import "fmt"

func main() {
	var x, a int
	fmt.Scanf("%d %d", &x, &a)
	result := (x >= a)
	result *= 10
	fmt.Println(result)
}

