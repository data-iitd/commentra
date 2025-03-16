
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	s := ""

	if n == 0 {
		fmt.Println("0")
		return
	}

	i := 1
	for n!= 0 {
		if n%2 == 0 {
			s += "0"
		} else {
			s += "1"
		}

		n -= abs(n%2)
		n /= -2
	}

	reverse(s)
	fmt.Println(s)
}

