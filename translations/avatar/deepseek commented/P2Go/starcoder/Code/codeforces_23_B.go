
package main

import "fmt"

func main() {
	var n int
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		var a int
		fmt.Scanf("%d", &a)
		if a < 2 {
			fmt.Println(0)
		} else {
			fmt.Println(a - 2)
		}
	}
}

