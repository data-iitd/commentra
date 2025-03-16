<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
	var a, b, c int
	var op byte

	fmt.Scanf("%d %c %d", &a, &op, &b)

	for {
		if op == '+' {
			c = a + b
			fmt.Println(c)
		} else if op == '-' {
			c = a - b
			fmt.Println(c)
		} else if op == '*' {
			c = a * b
			fmt.Println(c)
		} else if op == '/' {
			c = a / b
			fmt.Println(c)
		} else {
			break
		}

		fmt.Scanf("%d %c %d", &a, &op, &b)
	}
}

