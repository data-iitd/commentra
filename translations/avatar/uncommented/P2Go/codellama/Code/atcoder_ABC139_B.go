
package main

import "fmt"

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	hole := 1
	i := 0
	check := true
	for check {
		if hole >= b {
			check = false
		} else {
			hole = a * (i + 1) - i
			i++
		}
	}
	fmt.Println(i)
}

