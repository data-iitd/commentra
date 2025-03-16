<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
	var a, b int
	fmt.Scanf("%d", &a)
	fmt.Scanf("%d", &b)
	if (a*b)%2 == 0 {
		fmt.Println("Even")
	} else {
		fmt.Println("Odd")
	}
}
