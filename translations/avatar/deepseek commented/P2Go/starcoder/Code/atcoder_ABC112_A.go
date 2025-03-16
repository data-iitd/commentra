
package main

import "fmt"

func main() {
	var age int
	fmt.Scanf("%d", &age)
	if age == 1 {
		fmt.Println("Hello World")
	} else {
		var a, b int
		fmt.Scanf("%d %d", &a, &b)
		fmt.Println(a + b)
	}
}

