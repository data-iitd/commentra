
package main

import "fmt"

func main() {
	var a, b, c int64
	fmt.Scan(&a, &b, &c)
	d := c - a - b
	if d > 0 && (4*a*b) < (d*d) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

