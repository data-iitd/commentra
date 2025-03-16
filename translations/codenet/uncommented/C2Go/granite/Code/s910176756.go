
package main

import "fmt"

func main() {
	var a, b, c int
	var op byte
	fmt.Scanf("%d %c %d", &a, &op, &b)
	for {
		switch op {
		case '+':
			c = a + b
			fmt.Println(c)
		case '-':
			c = a - b
			fmt.Println(c)
		case '*':
			c = a * b
			fmt.Println(c)
		case '/':
			c = a / b
			fmt.Println(c)
		default:
			break
		}
		if _, err := fmt.Scanf("%d %c %d", &a, &op, &b); err!= nil {
			break
		}
	}
}

// 