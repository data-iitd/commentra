
package main

import "fmt"

func main() {
	n := 0
	fmt.Scan(&n)
	i, j := 1, n*n
	for i < j {
		fmt.Println(i, j)
		i++
		j--
	}
}

