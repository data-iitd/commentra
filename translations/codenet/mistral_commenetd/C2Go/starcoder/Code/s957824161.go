<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
	var x, y int
	fmt.Println("Enter two integers: ")
	fmt.Scanf("%d %d", &x, &y)
	result1 := x * y
	result2 := 2 * x + 2 * y
	fmt.Printf("The product of %d and %d is: %d\n", x, y, result1)
	fmt.Printf("The sum of 2 times %d and 2 times %d is: %d\n", x, y, result2)
}

