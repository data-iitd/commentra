
package main

import "fmt"

func main() {
	var princess, dragon, t, f, c int
	fmt.Scan(&princess)
	fmt.Scan(&dragon)
	fmt.Scan(&t)
	fmt.Scan(&f)
	fmt.Scan(&c)

	if dragon <= princess {
		fmt.Println(0)
		return
	}

	result := 0
	position := t * princess
	position += princess * position / (dragon - princess)

	for position < c {
		result++
		position += princess * position / dragon
		position += princess * f
		position += princess * position / (dragon - princess)
	}

	fmt.Println(result)
}

